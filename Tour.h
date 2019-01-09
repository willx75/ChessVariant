//
// Created by will2 on 05/01/2019.


#ifndef CHESSVARIANTS_TOUR_H
#define CHESSVARIANTS_TOUR_H


#include <string>
#include "Piece.h"

#include "Piece.h"
#include "Plateau.h"
#include "Position.h"


class Tour : public Deplacement {

public:
     Tour(Position m_debut, Position m_fin, Piece::Couleur couleur, Position position);

    // This function replaces the copyconstructor.
    //   * @return un pointeur vers la nouvelle piece cloner
    virtual Piece *clone() const;

    virtual std::list<Deplacement> getDeplacementPossibles(const Plateau &plateau) const;

    id type;
};



#endif //CHESSVARIANTS_TOUR_H
