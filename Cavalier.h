//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_CAVALIER_H
#define CHESSVARIANTS_CAVALIER_H


#include "Position.h"
#include "Piece.h"

class Cavalier {
    Cavalier(Piece::Couleur couleur, Position position);
    virtual Piece* clone() const;
    virtual std::list<Deplacement> deplacementPossible(const Plateau &plateau) const;

};


#endif //CHESSVARIANTS_CAVALIER_H
