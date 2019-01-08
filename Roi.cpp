//
// Created by will2 on 05/01/2019.
//
#include <cmath>
#include <wchar.h>
#include <iostream>
#include <string>
#include "Roi.h"
using namespace std;


Roi::Roi(Piece::Couleur couleur, Position position)
        : Piece(colour, position) {
    this->type = Piece::Roi;
}

Piece* Roi::clone() const {
    return new Roi(*this);
}

std::list<Deplacement> Roi::getPossibleDeplacements(const Board &board) const {
    std::list<Deplacement> Deplacements;
    if (!isCaptured()) {
        int x = this->position.getX();
        int y = this->position.getY();
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j ++) {
                int targetx = x + i;
                int targety = y + j;
                if (targetx >= 0 && targetx < 8 && targety >= 0 && targety < 8) {
                    if (board.getPiece(Position(targetx, targety)) != nullptr
                        && board.getPiece(Position(targetx, targety))->getColour() != this->getColour()) {
                        Deplacements.push_back(Deplacement(Position(x, y), Position(targetx, targety)));
                    } else if (board.getPiece(Position(targetx, targety)) == nullptr) {
                        Deplacements.push_back(Deplacement(Position(x, y), Position(targetx, targety)));
                    }
                }
            }
        }
        // Roque
        //lorque le roi se deplacement vers la droite il echange de place avec le fou
        if ((x == 0 || x == 7) && y == 4 && !this->wasDeplacementd()) {
            if (board.getPiece(Position(x, y + 1)) == nullptr
                && board.getPiece(Position(x, y + 2)) == nullptr
                && board.getPiece(Position(x, y + 3)) != nullptr
                && board.getPiece(Position(x, y + 3))->getType() == Piece::Tour
                && board.getPiece(Position(x, y + 3))->getColour() == this->color
                && !board.getPiece(Position(x, y + 3))->wasDeplacementd()) {
                Deplacements.push_back(Deplacement(Position(x, y), Position(x, y + 2)));

            }
            if (board.getPiece(Position(x, y - 1)) == nullptr
                && board.getPiece(Position(x, y - 2)) == nullptr
                && board.getPiece(Position(x, y - 3)) == nullptr
                && board.getPiece(Position(x, y - 4)) != nullptr
                && board.getPiece(Position(x, y - 4))->getType() == Piece::Tour
                && board.getPiece(Position(x, y - 4))->getColour() == this->color
                && !board.getPiece(Position(x, y - 4))->wasDeplacementd()) {
                Deplacements.push_back(Deplacement(Position(x, y), Position(x, y - 2)));

            }

        }
    }
    return Deplacements;
}
