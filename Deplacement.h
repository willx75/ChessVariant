//
// Created by will2 on 07/01/2019.
//

#include "Position.h"
#include "Piece.h"

#ifndef CHESSVARIANTS_DEPLACEMENT_H
//#define CHESSVARIANTS_DEPLACEMENT_H


class Deplacement {

public:
        enum DeplacementType : int {
            Normal = 0x00,
            Capture = 0x01,
            Roque = 0x02,
            Promotion = 0x04
        };

        Deplacement(Position m_debut, Position m_fin);

        Deplacement(const Deplacement &Deplacement);

        ~Deplacement();

        Position getDebut() const;

        Position getFin() const;

        void addType(DeplacementType type);

        bool hasType(DeplacementType type) const;

        Piece* getPieceCapturer() const;

        void setCaptureDeplacement(Piece *piece);

        bool operator==(const Deplacement &toCompare);
    private:
        Position m_debut;
        Position m_fin;
        int type;
        Piece *pieceCapturer;

        };


#endif //CHESSVARIANTS_DEPLACEMENT_H
