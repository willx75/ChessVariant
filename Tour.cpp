//
// Created by will2 on 05/01/2019.
//

#include "Tour.h"
#include "Plateau.h"

Tour::Tour(Position m_debut, Position m_fin, Piece::Couleur couleur, Position position) : Deplacement(m_debut, m_fin) {
    this->type = Piece::Tour;


    virtual std::list<Deplacement> getPossibleMoves(const Plateau &plateau) const;


    Piece *Tour::clone() const {
        return new Tour(*this);

    }


/**
 *
 * @param plateau
 * @return une liste de deplacement possible pour la piece Tour
 */
    std::list<Deplacement> Tour::deplacementPossible(const Plateau &plateau) const {
        std::list<Deplacement> deplacement;
        if (!isCaptured()) {
            bool haut = true;
            bool droite = true;
            bool bas = true;
            bool gauche = true;
            int i = 1;

            //mouvement possible de la Tour haut/bas/droite/gauche
            //on teste pour savoir si le deplacement de la piece peut marcher ou non

            while (haut || droite || bas || gauche) {
                checkMove(plateau, deplacement, haut, i, 0);
                checkMove(plateau, deplacement, droite, 0, i);
                checkMove(plateau, deplacement, bas, -i, 0);
                checkMove(plateau, deplacement, gauche, 0, -i);
                i++;
            }
        }
        return deplacement;
    }

