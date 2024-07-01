#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "coordinates.h"
using namespace std;

class Board;

class Piece {
public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NAME_NO_COLOR;
    string name;
    Coordinates position;
    int value;
    string color;
    Board *board;

    void move(Coordinates checkFinal);
    virtual int possibleMoves(Coordinates **&arrayMoves) = 0;
    Coordinates getPosition() const;
    friend ostream &operator<<(ostream &os, const Piece &p);
    Piece(string name, Coordinates position, string color, Board *board);
    virtual ~Piece();
};


class Queen : public Piece {
public:
    Queen(string name, Coordinates position, string color, Board* board);
    int possibleMoves(Coordinates**& arrayMoves) override;
};

#endif
