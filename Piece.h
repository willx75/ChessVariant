//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_PIECE_H
#define CHESSVARIANTS_PIECE_H

#include "Deplacement.h"
#include "Plateau.h"

class Piece {

protected:

    Couleur couleur;
    bool capture;
    Figure type;
    Position position;
    bool deplacer;

public:
    Piece(Couleur couleur, Position position);

    virtual Piece *clone() const = 0;

    Piece(int color);

    int getType() const;

    Couleur getCouleur() const;

    void setCapture();

    bool capturer() const;

    bool deplacementValide(Plateau &plateau, Deplacement &deplacement) const;
    virtual std::list<Deplacement> deplacementPossible(const Plateau &plateau) const = 0;

    Figure getType() const;

    Position    getPosition() const;

     Position setPosition(Position position);

    bool estDeplace() const;

    bool isCapture() const;

    bool isDeplacer() const;

    void setCouleur(const Couleur &couleur);

    void setCapture(bool capture);

    void setType(const Figure &type);

    void setDeplacer(bool deplacer);


    enum Figure {
        Roi, Reine, Pion, Cavalier, Tour, Fou
    };
    enum Couleur : bool {
        Black, White
    };

};


#endif //CHESSVARIANTS_PIECE_H
