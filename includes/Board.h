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
    char getCellValue(int index);
public:
  Board();
  void printBoard();
  bool setCellValue(int index, char value);
};