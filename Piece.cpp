//
// Created by will2 on 05/01/2019.
//

#include "Piece.h"
using namespace std;


Piece::Piece(Couleur colour, Position position)
        : colour(colour), capture(false), moved(false), position(position) {
}

void perform_capture() {
    this->capture = true ;
}

