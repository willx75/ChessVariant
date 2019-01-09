//
// Created by will2 on 05/01/2019.
//

#include "Fou.h"
#include "Plateau.h"

Fou::Fou(Plateau::Couleur couleur, Position position)
{
    this->type = Piece::Fou;
}

Piece* Fou::clone() const {
    return new Fou(*this);
}

std::list<Deplacement> ::getPossibleDeplacements(const Board &board) const {
    std::list<Deplacement> Deplacements;
    if (!isCaptured()) {
        bool leftTop = true;
        bool rightTop = true;
        bool leftBottom = true;
        bool rightBottom = true;
        int i = 1;

        while (leftTop || rightTop || leftBottom || rightBottom) {
            checkDeplacement(board, Deplacements, leftTop, i, -i);
            checkDeplacement(board, Deplacements, rightTop, i, i);
            checkDeplacement(board, Deplacements, leftBottom, -i, -i);
            checkDeplacement(board, Deplacements, rightBottom, -i, i);
            i++;
        }
    }
    return Deplacements;
}
