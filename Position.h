//
// Created by will2 on 05/01/2019.
//

#ifndef CHESSVARIANTS_POSITION_H
#define CHESSVARIANTS_POSITION_H


class Position {
public:
    Position();

    Position(int x, int y);

    bool isValid() const;

    int getX() const;

    int getY() const;

    int m_x, m_y;

};


#endif //CHESSVARIANTS_POSITION_H
