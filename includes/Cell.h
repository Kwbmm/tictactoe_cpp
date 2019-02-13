#pragma once

#include <vector>

class Cell
{
private:
    char value = ' ';
    std::vector<int> directions;

public:
    Cell(){};
    Cell(const std::vector<int>& directions);
    bool isTaken();
    char getValue();
    void setValue(char value);
};