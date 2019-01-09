//
// Created by will2 on 05/01/2019.
//

#include "Reine.h"
#include <cmath>
#include <wchar.h>
#include <iostream>
#include <string>
using namespace std;


string Reine::toString(){
    return "Q";
}
#include "Reine.h"
#include "Plateau.h"

Reine::Reine(Piece::Colour colour, Position position)
        : StraightLineDeplacementr(colour, position) {
    this->type = Piece::Reine;
}

Piece* Reine::clone() const {
    return new Reine(*this);
}

std::list<Deplacement> Reine::getPossibleDeplacements(const Plateau &Plateau) const {
    std::list<Deplacement> mouvement;
    if (!isCaptured()) {
        bool top = true;
        bool right = true;
        bool bottom = true;
        bool left = true;
        bool leftTop = true;
        bool rightTop = true;
        bool leftBottom = true;
        bool rightBottom = true;
        int i = 1;

        while (top || right || bottom || left || leftTop || rightTop || leftBottom || rightBottom) {
            checkDeplacement(Plateau, Deplacements, leftTop, i, -i);
            checkDeplacement(Plateau, Deplacements, rightTop, i, i);
            checkDeplacement(Plateau, Deplacements, leftBottom, -i, -i);
            checkDeplacement(Plateau, Deplacements, rightBottom, -i, i);
            checkDeplacement(Plateau, Deplacements, top, i, 0);
            checkDeplacement(Plateau, Deplacements, right, 0, i);
            checkDeplacement(Plateau, Deplacements, bottom, -i, 0);
            checkDeplacement(Plateau, Deplacements, left, 0, -i);
            i++;
        }
    }
    return Deplacements;
}
