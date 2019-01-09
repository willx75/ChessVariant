//
// Created by will2 on 05/01/2019.
//

#include "Pion.h"
#include "Pion.h"
#include "Position.h"
#include "Piece.h"

Pion::Pion(Piece::Couleur couleur, Position position): Piece(couleur, position) {
    this->type = Piece::Pion;
}

Piece* Pion::clone() const {
    return new Pion(*this);
}

std::list<Deplacement> Pion::deplacementPossible(const Plateau &plateau) const {
    std::list<Deplacement> d;
    if (!isCaptured()) {
        int x = this->position.getX();
        int y = this->position.getY();
        if (this->couleur == Piece::Couleur ::White) {
            if (plateau.getPiece(Position(x + 1, y)) == nullptr)
            { d.push_back(Deplacement(Position(x, y), Position(x + 1, y))); }
            //can Deplacement 2 fields!
            if (x == 1) {
                if (plateau.getPiece(Position(x + 1, y)) == nullptr &&
                    plateau.getPiece(Position(x + 2, y)) == nullptr) {
                    d.push_back(Deplacement(Position(x, y), Position(x + 2, y)));
                }
            }
            if(0 <= y - 1 && plateau.getPiece(Position(x + 1, y - 1)) != nullptr) {
                d.push_back(Deplacement(Position(x, y), Position(x + 1, y - 1)));
            }
            if(y + 1 < 8 && plateau.getPiece(Position(x + 1, y + 1)) != nullptr) {
                d.push_back(Deplacement(Position(x, y), Position(x + 1, y + 1)));
            }
        } else {
            if (plateau.getPiece(Position(x - 1, y)) == nullptr) {
                d.push_back(Deplacement(Position(x, y), Position(x - 1, y)));
            }
            //peut se deplacer de 2 cases
            if (x == 6) {
                if (plateau.getPiece(Position(x - 1, y)) == nullptr &&
                    plateau.getPiece(Position(x - 2, y)) == nullptr)
                { d.push_back(Deplacement(Position(x, y), Position(x - 2, y))); }
            }
            if(0 <= y - 1 && plateau.getPiece(Position(x - 1, y - 1)) != nullptr) {
                d.push_back(Deplacement(Position(x, y), Position(x - 1, y - 1)));
            }
            if(y + 1 < 8 && plateau.getPiece(Position(x - 1, y + 1)) != nullptr) {
                d.push_back(Deplacement(Position(x, y), Position(x - 1, y + 1)));
            }
        }
    }
    return d;
}
