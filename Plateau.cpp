//
// Created by will2 on 05/01/2019.
//

#include <iostream>
#include <list>
#include "Plateau.h"
#include "Piece.h"

using namespace std;


Plateau::Plateau() : currentColour(Couleur::White) {
    {
        this->plateau = creerPlateau();
    }
}


Plateau::Plateau(std::list<Deplacement *> deplacement) {}

Plateau::Plateau(std::list<Piece *> piece) {}

void Plateau::affichePlateau() {

    std::cout << "    A   B   C   D   E   F   G   H";;
    printHaut();
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << " │ ";
        for (int j = 0; j < 8; ++j) {
            affichePiece(plateau.getPiece(Position(i, j)));
            std::cout << " │ ";
        }
        std::cout << " " << i + 1 << std::endl;
        if (i < 7) {
            printBordure();
        }
    }
    printBas();
    std::cout << "    A   B   C   D   E   F   G   H";
}

void Plateau::printBordure() const {
    std::cout << "  ├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
}

void Plateau::printBas() const {
    std::cout << "  └───┴───┴───┴───┴───┴───┴───┴───┘" << std::endl;
}

void Plateau::printHaut() const {
    std::cout << "  ┌───┬───┬───┬───┬───┬───┬───┬───┐" << std::endl;
}

void affichePiece(Piece const *piece) {
    if (piece == nullptr) {
        std::cout << "  ";
        return;
    }
    if (piece->getCouleur() != Piece::Blanc) {
        switch (piece->getType()) {
            case Piece::Fou :
                std::cout << "F";
                break;
            case Piece::Roi :
                std::cout << "K";
                break;
            case Piece::Cavalier :
                std::cout << "C";
                break;
            case Piece::Pion :
                std::cout << "P";
                break;
            case Piece::Reine :
                std::cout << "Q";
                break;
            case Piece::Tour :
                std::cout << "T";
                break;
        }
    } else {
        switch (piece->getType()) {
            case Piece::Fou :
                std::cout << "F";
                break;
            case Piece::Roi :
                std::cout << "K";
                break;
            case Piece::Cavalier :
                std::cout << "C";
                break;
            case Piece::Pion :
                std::cout << "P";
                break;
            case Piece::Reine :
                std::cout << "Q";
                break;
            case Piece::Tour :
                std::cout << "T";
                break;
        }
    }


    Piece **Plateau::creerPlateau() {
        Piece **tab = new Piece *[8];

        for (int i = 0; i < 8; ++i) {
            tab[i] = new Piece[8];
            for (int j = 0; j < 8; ++j) {
                tab[i][j] = NULL;
            }
        }
        for (int k = 0; k < 8; ++k) {
            tab[1][k] = new Piece(Piece::getColor(), Position(1, k));
            tab[6][k] = new Piece(Piece::getColor(), Position(6, k));
        }

        return tab;
    }


}
