//
// Created by will2 on 05/01/2019.
//

#include "Piece.h"
#include "Plateau.h"

using namespace std;

 Piece::Piece(Couleur colour, Position position) :
        couleur(couleur), capture(false), deplacer(false), position(position) {
}
/**
 * GEtteur / Setteur
 * @return
 */
Piece::Couleur Piece::getCouleur() const {
    return couleur;
}

void Piece::setCapture() {
    this->capture = true;
}

bool Piece::capturer() const {
    return capture;
}

Piece::Figure Piece::getType() const {
    return this->type;
}

bool Piece::isCapture() const {
    return capture;
}

bool Piece::isDeplacer() const {
    return deplacer;
}

Position Piece::getPosition() const {
    return this->position;
}

void Piece::setPosition(Position position) {
    this->position = position;
    this->deplacer = true;
}

void Piece::setCouleur(const Couleur &couleur) {
    Piece::couleur = couleur;
}

void Piece::setCapture(bool capture) {
    Piece::capture = capture;
}

void Piece::setType(const Figure &type) {
    Piece::type = type;
}

void Piece::setDeplacer(bool deplacer) {
    Piece::deplacer = deplacer;
}

bool Piece::estDeplace() const {
    return this->deplacer;
}

/**
 *
 * @param plateau
 * @param deplacement
 * @return true
 *
 * on teste pour un plateau donnée si le deplacement que l'on veut faire est valide ou pas pour la piece courante(qu'on use)
 *On utilise une liste de deplacement afin de voir cela, on appelle a cela la methdoe
 * deplacementPossible pour voir si le mouvement est possoble ou non!!
 */
bool Piece::deplacementValide(Plateau &plateau, Deplacement &deplacement) const {
    std::list<Deplacement> move = this->deplacementPossible(plateau);
    std::list<Deplacement>::iterator iterator1;
    for (iterator1 = move.begin(); iterator1 != move.end(); ++iterator1) {
        if (*iterator1 == deplacement) {
            return true;
        }
    }
    return false;
}


