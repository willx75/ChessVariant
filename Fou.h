//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_FOU_H
#define CHESSVARIANTS_FOU_H


#include <string>
#include "Position.h"
#include "Piece.h"

class Fou {
public:

    std::string toString();

    Fou(Piece::Couleur couleur, Position position);

    virtual std::list<Deplacement> getPossibleMoves(const Plateau &plateau) const;


    virtual Piece *clone() const;


};;


#endif //CHESSVARIANTS_FOU_H
