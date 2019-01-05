//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_PIECE_H
#define CHESSVARIANTS_PIECE_H


class Piece {
    enum Figure {
        Roi, Reine, Pion, Cavalier, Tour, Fou
    };
    enum Couleur {
        Black, White
    };

protected:

    Couleur couleur;
    bool capture;

public:
    Piece(int color);

    int getType() const;


    void capture();

    bool estCapture() const;

    //  bool isMoveValid(Plateau &plateau, Deplacement &deplacement ) const ;
};


#endif //CHESSVARIANTS_PIECE_H
