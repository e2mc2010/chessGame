#include "piece.h"
#include <iostream>

using namespace std;

const string Piece::NAME_BLACK = "black";
const string Piece::NAME_WHITE = "white";
const string Piece::NAME_NO_COLOR = "*";

Piece::Piece(string name, Coordinates position, string color, Board *board)
    : name(name), position(position), color(color), board(board), value(0) {}

Piece::~Piece() {}

void Piece::move(Coordinates finalPosition) {
    position = finalPosition;
}

Coordinates Piece::getPosition() const {
    return position;
}

ostream &operator<<(ostream &os, const Piece &p) {
    os << p.name << " at " << p.position << " (" << p.color << ")";
    return os;
}


Queen::Queen(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 9;
}

int Queen::possibleMoves(Coordinates **&arrayMoves) {



    for (int i = 0; i < 8; ++i) {
        delete arrayMoves[i];
    }
    delete[] arrayMoves;

    arrayMoves = new Coordinates *[8];
    int count = 0;


    static const int moveOffsets[8][2] = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, 
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}  
    };

    for (int i = 0; i < 8; ++i) {
        char newCol = position.getColumn() + moveOffsets[i][0];
        int newRow = position.getRow() + moveOffsets[i][1];

        if (newCol >= 'a' && newCol <= 'h' && newRow >= 1 && newRow <= 8) {
            Coordinates *newMove = new Coordinates(newCol, newRow);
            arrayMoves[count++] = newMove;
        }
    }

    return count;
}
