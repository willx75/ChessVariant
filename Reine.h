//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_REINE_H
#define CHESSVARIANTS_REINE_H


#include <string>
#include "Piece.h"
#include "Position.h"
#include "Plateau.h"

class Reine :: public Piece {

public:

std::string toString() ;

Reine(Piece::Couleur couleur, Position position );


virtual std::list<Deplacement> getPossibleMoves(const Plateau &plateau) const;

};


#endif //CHESSVARIANTS_REINE_H
