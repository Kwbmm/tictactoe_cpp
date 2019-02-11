#include <iostream>
#include "includes/Board.h"

void Board::printBoard() {
    std::cout << "-------+-------+-------" << std::endl;
    for(int i = 0; i < Board::boardSize; i++)
    {
        if (i % 3 == 0) {
            std::cout << "       |       |       " << std::endl;
        }
        std::cout << printCell(i);
        if ((i+1) % 3 == 0) {
            std::cout << std::endl;
            std::cout << "       |       |       " << std::endl;
            std::cout << "-------+-------+-------" << std::endl;
        }
    }
}

bool Board::isCellFree(int cellNumber) {
    return state[cellNumber] != '0' && state[cellNumber] != 'x';
}

std::string Board::printCell(int index) {
    if (index == 0 || index == 3 || index == 6) {
        std::string cell = "   ";
        return cell.append(1, state[index]).append("   |");
    }
    if (index == 1 || index == 4 || index == 7) {
        std::string cell = "   ";
        return cell.append(1, state[index]).append("   ");
    }
    if (index == 2 || index == 5 || index == 8) {
        std::string cell = "|   ";
        return  cell.append(1, state[index]).append("   ");
    }
    return "";
}