#include <iostream>
#include <vector>
#include "includes/Board.h"
#include "includes/Cell.h"

Board::Board(void) {
    state = {
        Cell(std::vector<int> {}),
        Cell(std::vector<int> {0, 2}),
        Cell(std::vector<int> {}),
        Cell(std::vector<int> {0, 6}),
        Cell(std::vector<int> {0, 1, 2, 3, 5, 6, 7, 8}),
        Cell(std::vector<int> {2, 8}),
        Cell(std::vector<int> {}),
        Cell(std::vector<int> {6, 8}),
        Cell(std::vector<int> {}),
    };
}

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

std::string Board::printCell(int index) {
    if (index == 0 || index == 3 || index == 6) {
        std::string cell = "   ";
        return cell.append(1, state[index].getValue()).append("   |");
    }
    if (index == 1 || index == 4 || index == 7) {
        std::string cell = "   ";
        return cell.append(1, state[index].getValue()).append("   ");
    }
    if (index == 2 || index == 5 || index == 8) {
        std::string cell = "|   ";
        return  cell.append(1, state[index].getValue()).append("   ");
    }
    return "";
}