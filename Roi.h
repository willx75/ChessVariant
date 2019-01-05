//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_ROI_H
#define CHESSVARIANTS_ROI_H


class Roi :: Piece {
public:

    std::string toString();

    Roi(Piece::Couleur couleur, Position position );
    );

    virtual std::list<Mouvement> getPossibleMoves(const Plateau &plateau) const;

};;




#endif //CHESSVARIANTS_ROI_H
