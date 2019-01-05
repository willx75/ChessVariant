//
// Created by will2 on 05/01/2019.
//

#include "Plateau.h"
using namespace std;
Plateau::Plateau():currentColour(Piece::Couleur::White) {
    {
        this->plateau = creerPlateau() ;
    }
    Plateau::Plateau(std::list<Piece *> piece) {

    }
    void Plateau::affichePlateau(Plateau *board) {

        std::cout << "    A   B   C   D   E   F   G   H";;
        printHaut();
        for (int i = 0; i < 8; ++i) {
            std::cout << i + 1 << " │ ";
            for (int j = 0; j < 8; ++j) {
//            affichePiece(board->getPiece(Position(i, j)));
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
        if (piece == NULL) {
            std::cout << "  ";
            return;
        }
    }

    /**if (piece->getColor() != Piece::getColor()) {
         switch (piece->getType()) {
             case Tour :
                 std::cout << "T";
                 break;

         }
     }**/

    Piece** Plateau::creerPlateau() {
        Piece *** tab = new Piece **[8] ;

        for (int i = 0; i <8 ; ++i) {
            tab[i] = new Piece *[8];
            for (int j = 0; j < 8 ; ++j) {
                tab[i][j] = NULL ;
            }
        }
        for (int k = 0; k <8 ; ++k) {
            tab[1][k] = new Pion(Piece::getColor(),Position(1,k)) ;
            tab[6][k] = new Pion(Piece::getColor(),Position(6,k)) ;
        }
    }
    Plateau::Plateau(std::list < Deplacement * > deplacement)
    {

    }


