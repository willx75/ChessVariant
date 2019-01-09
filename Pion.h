//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_PION_H
#define CHESSVARIANTS_PION_H


#include "Deplacement.h"
#include "Position.h"

class Pion {


    Pion(Piece::Couleur couleur, Position position);

    virtual Piece *clone() const;

    virtual std::list<Deplacement> deplacementPossible(const Plateau &plateau) const;

};


#endif //CHESSVARIANTS_PION_H
