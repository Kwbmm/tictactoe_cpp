#include "includes/Cell.h"

Cell::Cell(const std::vector<int>& directions): directions(directions){}

bool Cell::isTaken() {
    return value != ' ';
}

char Cell::getValue() {
    return value;
}

void Cell::setValue(char value) {
    this->value = value;
}
