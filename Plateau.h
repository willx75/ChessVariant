//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_PLATEAU_H
#define CHESSVARIANTS_PLATEAU_H


#include "Piece.h"
#include "Position.h"

class Plateau {

public:
    Plateau();

    Plateau(const Plateau &plateau);

    /**
     * @param deplacement une liste de deplacement qui sont appliquer au plateau de jeu
     */
    Plateau(std::list<Deplacement *> deplacement);

    //destructeur qui supprimera chaque piece du plateau
    virtual ~Plateau();

    void affichePlateau(Plateau *board);

private:
    void printBordure() const;

    void printBas() const;

    void printHaut() const;

    void affichePiece(Piece const *piece) const;

    std::list<Piece *> listPiece;

    Piece *getPiece(Position position) const;

    Piece* *creerPlateau() ;

    Piece **plateau;
};


#endif //CHESSVARIANTS_PLATEAU_H
