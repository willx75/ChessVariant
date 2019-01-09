//
// Created by will2 on 05/01/2019.
//

#include "Fou.h"
#include "Plateau.h"

Fou::Fou(Plateau::Couleur couleur, Position position) {
    this->type = Piece::Fou;
}

Piece *Fou::clone() const {
    return new Fou(*this);
}

Fou::checkDeplacement(const Plateau &board, std::list<Deplacement> &d,
                      bool &direction, int dx, int dy) const {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();

    if (!direction) {
        return;
    }
    Position p = Position(x + dx, y + dy);
    if (!p.isValid()) {
        direction = false;
        return;
    }
    if (board.getPiece(p) != nullptr) {
        direction = false;
        if (board.getChessman(p)->getColour() != this->couleur) {
            d.push_back(Deplacement(Position(x, y), p));
        }
    } else {
        d.push_back(Deplacement(Position(x, y), p));
    }
}

std::list<Deplacement> Fou::deplacementPossible(const Plateau &plateau) const {
    std::list<Deplacement> d;
    if (!isCaptured()) {
        bool diagGauche = true;
        bool diagDroite = true;
        bool diagBasGauche = true;
        bool diagBasDroite = true;
        int i = 1;

        while (diagGauche || diagDroite || diagBasGauche || diagBasDroite) {
            checkDeplacement(plateau, d, diagGauche, i, -i);
            checkDeplacement(plateau, d, diagDroite, i, i);
            checkDeplacement(plateau, d, diagBasGauche, -i, -i);
            checkDeplacement(plateau, d, diagBasDroite, -i, i);
            i++;
        }
    }
    return d;
}
