//
// Created by will2 on 01/01/2019.
//

#include "Partie.h"


#include "Pion.h"
#include "Reine.h"
#include "Roi.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Deplacement.h"
#include "Position.h"
#include "Fou.h"


#include <iostream>

Plateau::Plateau(): currentCouleur(Piece::Couleur::White) {
    this->Plateau = ();
}

Plateau::Plateau(std::list<Deplacement *> deplacement): currentCouleur(Piece::Couleur::White) {
    this->Plateau = start();
    while (deplacement.size() != 0) {
        applyMove(deplacement.front());
        delete deplacement.front();
        deplacement.pop_front();
    }
}

Plateau::Plateau(const Plateau &b) {
    this->Plateau = new Piece **[8];

    for (int x = 0; x < 8; x++) {
        this->Plateau[x] = new Piece *[8];
        for (int y = 0; y < 8; y++) {
            if (b.getPiece(Position(x, y)) != nullptr) {
                this->Plateau[x][y] = b.getPiece(Position(x, y))->clone();
            }
        }
    }
    for (Piece *c : b.capturedChessmen) {
        this->capturedChessmen.push_back(c->clone());
    }
    for (Deplacement *d : d.previousMoves) {
        this->previousMoves.push_back(new Deplacement(*d));
    }
}

Plateau::~Plateau() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (this->Plateau[x][y] != nullptr) {
                delete this->Plateau[x][y];
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        delete[] this->Plateau[i];
    }
    delete[] this->Plateau;
    for (Piece *c : this->capturedChessmen) {
        delete c;
    }
    for (Move *m : this->previousMoves) {
        delete m;
    }
}

std::list<Deplacement> Plateau::getAllPossibleMoves(Piece::Couleur Couleur) const {
    std::list<Deplacement> list;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (this->Plateau[i][j] != nullptr && this->Plateau[i][j]->getCouleur() == Couleur) {
                list.splice(list.end(), this->Plateau[i][j]->getPossibleMoves(*this));
            }
        }
    }
    return list;
}

std::list<Deplacement *> Plateau::getPreviousMoves() const {
    return this->previousMoves;
}

Piece ***Plateau::start() {
    Piece ***array2d = new Piece **[8];

    for (int i = 0; i < 8; i++) {
        array2d[i] = new Piece *[8];
        for (int j = 0; j < 8; j++) {
            array2d[i][j] = nullptr;
        }
    }
    for (int i = 0; i < 8; i++) {
        array2d[1][i] = new Pion(Piece::Couleur ::White, Position(1, i));
        array2d[6][i] = new Pion(Piece::Couleur ::Black, Position(6, i));
    }

    array2d[0][0] = new Tour(Piece::Couleur::White, Position(0, 0));
    array2d[0][7] = new Tour(Piece::Couleur::White, Position(0, 7));
    array2d[7][0] = new Tour(Piece::Couleur::Black, Position(7, 0));
    array2d[7][7] = new Tour(Piece::Couleur::Black, Position(7, 7));
    array2d[0][1] = new Cavalier(Piece::Couleur::White, Position(0, 1));
    array2d[0][6] = new Cavalier(Piece::Couleur::White, Position(0, 6));
    array2d[7][1] = new Cavalier(Piece::Couleur::Black, Position(7, 1));
    array2d[7][6] = new Cavalier(Piece::Couleur::Black, Position(7, 6));
    array2d[0][2] = new Fou(Piece::Couleur::White, Position(0, 2));
    array2d[0][5] = new Fou(Piece::Couleur::White, Position(0, 5));
    array2d[7][2] = new Fou(Piece::Couleur::Black, Position(7, 2));
    array2d[7][5] = new Fou(Piece::Couleur::Black, Position(7, 5));
    array2d[0][3] = new Reine(Piece::Couleur::White, Position(0, 3));
    array2d[0][4] = new Roi(Piece::Couleur::White, Position(0, 4));
    array2d[7][3] = new Reine(Piece::Couleur::Black, Position(7, 3));
    array2d[7][4] = new Roi(Piece::Couleur::Black, Position(7, 4));
    return array2d;
}

Piece *Plateau::getPiece(Position position) const {
    return this->Plateau[position.getX()][position.getY()];
}
/**
bool Plateau::applyMove(Move *move) {
    Piece *currentPiece = getPiece(move->getOrigin());
    bool isCheck = this->isCheck();

    if (currentPiece != nullptr
        && currentPiece->isMoveValid(*this, *move)
        && currentPiece->getCouleur() == currentCouleur) {
        Plateau::move(move);
        // check casteling
        Position *rookTarget = nullptr;
        Position *rookOrigin = nullptr;
        if (currentPiece->getType() == Piece::FigureType::King
            && move->getOrigin().getY() - move->getTarget().getY() == 2) {
            rookTarget = new Position(move->getTarget().getX(), move->getTarget().getY() + 1);
            rookOrigin = new Position(move->getTarget().getX(), 0);
        }
        if (currentPiece->getType() == Piece::FigureType::King
            && move->getOrigin().getY() - move->getTarget().getY() == -2) {
            rookTarget = new Position(move->getTarget().getX(), move->getTarget().getY() - 1);
            rookOrigin = new Position(move->getTarget().getX(), 7);
        }
        if (rookTarget != nullptr) {
            Move *m = new Move(*rookOrigin, *rookTarget);
            Plateau::move(m);
            previousMoves.back()->addType(Move::Casteling);
            delete m;
            delete rookOrigin;
            delete rookTarget;
        }


        //check if after the move the player is still in check
        if (isCheck && this->isCheck()) {
            changeCurrentCouleur();
            this->undoLastMove();
            return false;
        }

        changeCurrentCouleur();

        return true;
    }
    return false;
}

void Plateau::move(Move *move) {

    Position origin = move->getOrigin();
    Position target = move->getTarget();
    Piece *currentPiece = this->Plateau[origin.getX()][origin.getY()];
    this->Plateau[origin.getX()][origin.getY()] = nullptr;

    Piece *targetPiece = this->Plateau[target.getX()][target.getY()];
    if (targetPiece != nullptr) {
        targetPiece->capture();
        move->setCaptureMove(targetPiece);
        capturedChessmen.push_back(targetPiece);
    }
    this->Plateau[target.getX()][target.getY()] = currentPiece;
    currentPiece->setCurrentPosition(target);
    this->previousMoves.push_back(new Move(*move));
}

void Plateau::applyPromotion(Move *move, Piece::FigureType type) {
    Piece *currentPiece = getPiece(move->getTarget());
    move->addType(Move::Promotion);
    int x = move->getTarget().getX();
    int y = move->getTarget().getY();
    switch (type) {
        case Piece::Queen :
            Plateau[x][y] = new Queen(currentPiece->getCouleur(), Position(x, y));
            break;
        case Piece::Rook :
            Plateau[x][y] = new Rook(currentPiece->getCouleur(), Position(x, y));
            break;
        case Piece::Fou :
            Plateau[x][y] = new Fou(currentPiece->getCouleur(), Position(x, y));
            break;
        case Piece::Cavalier :
            Plateau[x][y] = new Cavalier(currentPiece->getCouleur(), Position(x, y));
            break;
        default:
            break;
    }
    Move *m = previousMoves.back();
    previousMoves.pop_back();
    delete m;
    previousMoves.push_back(new Move(*move));
    capturedChessmen.push_back(currentPiece);
    delete move;
}

void Plateau::undoLastMove() {
    if (previousMoves.size() == 0) {
        return;
    }
    Move *m = previousMoves.back();
    previousMoves.pop_back();

    Position origin = m->getOrigin();
    Position target = m->getTarget();
    Piece *currentPiece = this->Plateau[target.getX()][target.getY()];
    if (m->hasType(Move::Promotion)) {
        delete currentPiece;
        currentPiece = capturedChessmen.back();
        capturedChessmen.pop_back();
    }

    if (m->hasType(Move::Capture)) {
        this->Plateau[target.getX()][target.getY()] = m->getCapturedPiece()->clone();
        this->Plateau[target.getX()][target.getY()]->unsetCapture();
    } else {
        this->Plateau[target.getX()][target.getY()] = nullptr;
    }
    this->Plateau[origin.getX()][origin.getY()] = currentPiece;
    currentPiece->setCurrentPosition(origin);

    if (m->hasType(Move::Casteling)) {
        this->changeCurrentCouleur();
        undoLastMove();
    }
    this->changeCurrentCouleur();
    delete m;
}

void Plateau::changeCurrentCouleur() {
    if (this->currentCouleur == Piece::Couleur::White) {
        this->currentCouleur = Piece::Couleur::Black;
    } else {
        this->currentCouleur = Piece::Couleur::White;
    }
}

bool Plateau::isCheck() const {
    std::list<Move> moves = getAllPossibleMoves(!this->currentCouleur);
    for (Move m : moves) {
        Piece *target = Plateau[m.getTarget().getX()][m.getTarget().getY()];
        if (target != nullptr
            && target->getType() == Piece::FigureType::King
            && target->getCouleur() == this->currentCouleur) {
            return true;
        }
    }
    return false;
}

bool Plateau::isCheckmate() const {
    if (!this->isCheck()) {
        return false;
    }
    std::list<Move> moves = getAllPossibleMoves(this->currentCouleur);
    Plateau *b = new Plateau(*this);
    for (Move m : moves) {
        Move *m2 = new Move(m);
        if (b->applyMove(m2)) {
            delete b;
            delete m2;
            return false;
        }
        delete m2;
        b->undoLastMove();
    }
    return true;
}

bool Plateau::isDraw() const {
    if (!this->isCheck() && getAllPossibleMoves(!this->currentCouleur).size() == 0) {
        return true;
    }
    return false;
}

bool Plateau::isPromotion(Deplacement *deplacement) const {
    Piece *currentPiece = getPiece(move->getTarget());
    if (currentPiece == nullptr) {
        return false;
    }
    if (currentPiece->getType() != Piece::Pawn) {
        return false;
    }
    if (move->getTarget().getX() == 0 || move->getTarget().getX() == 7) {
        move->addType(Move::Promotion);
        return true;
    }
    return false;
}
**/