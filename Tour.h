//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_TOUR_H
#define CHESSVARIANTS_TOUR_H


#include <string>
#include "Piece.h"

class Tour::

public Piece{

#include "Piece.h"
#include "Plateau.h"
#include "Position.h"


public:

std::string toString();

Tour(Piece::Couleur
couleur,
Position position
);


virtual std::list <Mouvement> getPossibleMoves(const Plateau &plateau) const;

};


#endif //CHESSVARIANTS_TOUR_H
