#include "board.h"

const string Square::NAME_BLACK = "black";
const string Square::NAME_WHITE = "white";
const string Square::NAME_NO_COLOR = "*";

Square::Square() : coordinates('a', 1), color(NAME_NO_COLOR), piece(nullptr) {}

Square::Square(Coordinates crdns, string clr, Piece *pp) : coordinates(crdns), color(clr), piece(pp) {}

Square::~Square() {}

void Square::setCoordinatesColor(char column, int row) {
    coordinates.setColumn(column);
    coordinates.setRow(row);
    if ((column - 'a' + row) % 2 == 0)
        color = NAME_WHITE;
    else
        color = NAME_BLACK;
}

void Square::setColor(string clr) {
    color = clr;
}

void Square::setPiece(Piece *pp) {
    piece = pp;
}

Coordinates Square::getCoordinates() {
    return coordinates;
}

char Square::getColumn() {
    return coordinates.getColumn();
}

int Square::getRow() {
    return coordinates.getRow();
}

string Square::getColor() {
    return color;
}

Piece *Square::getPiece() {
    return piece;
}

Board::Board() : numRows(8), numColumns(8), squares(numRows * numColumns) {
    initializeSquares();
}

Board::Board(int dim) : numRows(dim), numColumns(dim), squares(numRows * numColumns) {
    initializeSquares();
}

Board::Board(int dim, string array_char_position) : numRows(dim), numColumns(dim), squares(numRows * numColumns) {
    initializeSquares();

    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1);
            char pieceChar = array_char_position[r * numColumns + c];
            if (pieceChar != '-') {
                string pieceColor = isupper(pieceChar) ? Piece::NAME_WHITE : Piece::NAME_BLACK;
                Piece *newPiece = nullptr;
                switch (tolower(pieceChar)) {
                    case 'q':  // Change 'n' to 'q' for Queen
                        newPiece = new Queen("Queen", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                        break;
                }
                squares[r * numColumns + c].setPiece(newPiece);
            }
        }
    }
}

Board::~Board() {
    for (auto &square : squares) {
        delete square.getPiece();
    }
}

void Board::initializeSquares() {
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1);
        }
    }
}

void Board::setNumRows(int rws) {
    numRows = rws;
}

void Board::setNumColumns(int clmns) {
    numColumns = clmns;
}

int Board::getNumRows() {
    return numRows;
}

int Board::getNumColumns() {
    return numColumns;
}

vector<Square>& Board::getSquares() {
    return squares;
}

Piece *Board::pieceEn(char column, int row) {
    return squares[(row - 1) * numColumns + (column - 'a')].getPiece();
}

Piece *Board::pieceEn(Coordinates *position) {
    return squares[(position->getRow() - 1) * numColumns + (position->getColumn() - 'a')].getPiece();
}
