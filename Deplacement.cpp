//
// Created by will2 on 07/01/2019.
//

#include "Deplacement.h"
#include "Deplacement.h"
#include "Position.h"

Deplacement::Deplacement(Position debut, Position fin)
        : m_debut(debut), m_fin(fin), type(Deplacement::DeplacementType::Normal), pieceCapturer(nullptr) {
}

Deplacement::Deplacement(Position debut, Position fin, Deplacement::DeplacementType type) 
: m_debut(debut), m_fin(fin), type(type), pieceCapturer(nullptr) {
}

Deplacement::Deplacement(const Deplacement &Deplacement)
        : m_debut(Deplacement.m_debut), m_fin(Deplacement.m_fin), type(Deplacement.type), pieceCapturer(){
    if(Deplacement.getPieceCapturer() == nullptr) {
        this->pieceCapturer= nullptr;
    } else {
        this->pieceCapturer = Deplacement.getPieceCapturer()->clone();
    }
}


Deplacement::~Deplacement() {
    if(this->pieceCapturer != nullptr) {
        delete this->pieceCapturer;
    }
}

Position Deplacement::getDebut() const {
    return this->m_debut;
}

Position Deplacement::getFin() const {
    return this->m_fin;
}

void Deplacement::addType(DeplacementType type) {
    this->type |= type;
}

bool Deplacement::hasType(DeplacementType type) const {
    return this->type & type;
}

Piece* Deplacement::getPieceCapturer() const {
    return this->pieceCapturer;
}

void Deplacement::setCaptureDeplacement(Piece *piece) {
    this->addType(Deplacement::Capture);
    this->pieceCapturer = piece->clone();
}

bool Deplacement::operator==(const Deplacement &toCompare) {
    if (this->getDebut() == toCompare.getDebut()) {
        return this->getFin() == toCompare.getFin()
               && this->type == toCompare.type;
    } else {
        return false;
    }
}
