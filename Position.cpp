//
// Created by will2 on 05/01/2019.
//

#include "Position.h"

Position::Position() {}

Position::Position(int x, int y) : m_x(x), m_y(y) {
}


int Position::getX() const {
    return this->m_x;
}

int Position::getY() const {
    return this->m_y;
}

bool Position::isValid() const {
    return this->m_x >= 0 && this->m_x < 8 && this->m_y >= 0 && this->m_y < 8;
}