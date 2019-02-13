#pragma once

#include <string>
#include <array>
#include "Cell.h"

class Board
{
private:
    static const int boardSize = 9;
    std::array<Cell, boardSize> state;
    std::string printCell(int index);
public:
  Board();
  void printBoard();
};