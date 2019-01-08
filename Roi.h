//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_ROI_H
#define CHESSVARIANTS_ROI_H


#include "Piece.h"
#include "Plateau.h"

class Roi::

public Piece {
public:

std::string toString();

Roi(Piece::Couleur
couleur,
Position position
);


virtual std::list<Deplacement> getPossibleMoves(const Plateau &plateau) const;

};;


#endif //CHESSVARIANTS_ROI_H
