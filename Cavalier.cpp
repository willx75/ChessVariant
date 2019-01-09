//
// Created by will2 on 05/01/2019.
//

#include "Cavalier.h"
#include "Plateau.h"
#include "Position.h"
#include "Piece.h"

Cavalier::Cavalier(Piece::Couleur Couleur, Position position)
        : Piece(Couleur, position) {
    this->type = Piece::Cavalier;
}

Piece* Cavalier::clone() const {
    return new Cavalier(*this);
}

std::list<Deplacement> Cavalier::deplacementPossible(const Plateau &board) const {
    std::list<Deplacement> d;
    if (!isCaptured()) {
        int x = this->getCurrentPosition().getX();
        int y = this->getCurrentPosition().getY();
        std::list<Position> positions = {
                Position(x + 2, y - 1), Position(x + 1, y - 2), Position(x + 2, y + 1),
                Position(x + 1, y + 2), Position(x - 2, y - 1), Position(x - 1, y - 2),
                Position(x - 2, y + 1),  Position(x - 1, y + 2)
        };

        for (Position p : positions) {
            if (p.isValid())
            { d.push_back(Deplacement(Position(x, y), p)); }
        }
    }
    return d;
}
