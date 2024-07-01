#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>

class Coordinates {
public:
    Coordinates();
    Coordinates(char column, int row);
    Coordinates(const Coordinates &crdns);

    char getColumn() const;
    int getRow() const;

    void setColumn(char clmn);
    void setRow(int row);

    friend std::ostream &operator<<(std::ostream &os, const Coordinates &crdns);

private:
    char column;
    int row;
};

#endif // COORDINATES_H
