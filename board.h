#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "coordinates.h"
#include "piece.h"

using namespace std;

class Square {
private:
    Coordinates coordinates;
    string color;
    Piece *piece;

public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NAME_NO_COLOR;

    Square();
    Square(Coordinates crdns, string clr, Piece *pp);
    ~Square();

    void setCoordinatesColor(char column, int row);
    void setColor(string color);
    void setPiece(Piece *pp);

    Coordinates getCoordinates();
    char getColumn();
    int getRow();
    string getColor();
    Piece *getPiece();
};

// Board class
class Board {
private:
    int numRows, numColumns;
    vector<Square> squares;

public:
    Board();
    Board(int dim);
    Board(int dim, string array_char_position);
    ~Board();

    void setNumRows(int rws);
    void setNumColumns(int clmns);

    int getNumRows();
    int getNumColumns();
    vector<Square>& getSquares();

    Piece *pieceEn(char column, int row);
    Piece *pieceEn(Coordinates* position);

private:
    void initializeSquares();
};

#endif

