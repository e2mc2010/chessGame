#include "coordinates.h"

Coordinates::Coordinates() : column('a'), row(1) {}

Coordinates::Coordinates(char column, int row) : column(column), row(row) {}

Coordinates::Coordinates(const Coordinates &crdns) : column(crdns.column), row(crdns.row) {}

char Coordinates::getColumn() const {
    return column;
}

int Coordinates::getRow() const {
    return row;
}

void Coordinates::setColumn(char clmn) {
    column = clmn;
}

void Coordinates::setRow(int row) {
    this->row = row;
}

std::ostream &operator<<(std::ostream &os, const Coordinates &crdns) {
    os << "[" << crdns.getColumn() << ", " << crdns.getRow() << "]";
    return os;
}
