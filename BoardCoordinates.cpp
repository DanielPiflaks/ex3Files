/******************************************
Student name: Daniel Piflaks
Student ID: 311322986
Course Exercise Group: 05
Exercise name: Ex2
******************************************/

#include "BoardCoordinates.h"

BoardCoordinates::BoardCoordinates(int const row, int const column) : row(row), column(column) {}

int BoardCoordinates::getRow() const {
    return row;
}

int BoardCoordinates::getColumn() const {
    return column;
}

bool BoardCoordinates::operator>(const BoardCoordinates &boardCoordinates) const {
    if (getRow() == boardCoordinates.getRow()) {
        return (getColumn() > boardCoordinates.getColumn());
    } else {
        return (getRow() > boardCoordinates.getRow());
    }
}

bool BoardCoordinates::operator<(const BoardCoordinates &boardCoordinates) const {
    if (getRow() == boardCoordinates.getRow()) {
        return (getColumn() < boardCoordinates.getColumn());
    } else {
        return (getRow() < boardCoordinates.getRow());
    }
}

bool BoardCoordinates::operator==(const BoardCoordinates &boardCoordinates) const {
    return ((getRow() == boardCoordinates.getRow()) &&
            (getColumn() == boardCoordinates.getColumn()));
}

ostream &operator<<(ostream &OS, const BoardCoordinates &BC) {
    OS << '(' << BC.getRow() << ',' << BC.getColumn() << ')';
    return OS;
}

