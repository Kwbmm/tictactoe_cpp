#include <iostream>
#include <vector>
#include <stdio.h>
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

char Board::getCellValue(int index) {
    char ascii_repr [1] = {0};
    sprintf(ascii_repr, "%d", index+1);
    return state[index].getValue() == ' ' ? ascii_repr[0] : state[index].getValue();
}

std::string Board::printCell(int index) {
    if (index == 0 || index == 3 || index == 6) {
        std::string cell = "   ";
        return cell.append(1, getCellValue(index)).append("   |");
    }
    if (index == 1 || index == 4 || index == 7) {
        std::string cell = "   ";
        return cell.append(1, getCellValue(index)).append("   ");
    }
    if (index == 2 || index == 5 || index == 8) {
        std::string cell = "|   ";
        return  cell.append(1, getCellValue(index)).append("   ");
    }
    return "";
}

bool Board::setCellValue(int index, char value) {
    if (index < 0 || index > 8) {
        return false;
    }
    
    if (state[index].isTaken()) {
        return false;
    }
    state[index].setValue(value);
    return true;
}

bool Board::hasWinner(int index, char player) {
    switch (index)
    {
        case 0: //Top Left
            //123
            if (state[1].getValue() == player && state[2].getValue() == player) {
                return true;
            }
            //147
            if (state[3].getValue() == player && state[6].getValue() == player) {
                return true;
            }
            //159
            if (state[4].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            return false;
        case 1: //Top middle
            //123
            if (state[0].getValue() == player && state[2].getValue() == player) {
                return true;
            }
            //258
            if (state[4].getValue() == player && state[7].getValue() == player) {
                return true;
            }
            return false;
        case 2: // Top right
            //123
            if (state[0].getValue() == player && state[1].getValue() == player) {
                return true;
            }
            //369
            if (state[5].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            //357
            if (state[4].getValue() == player && state[6].getValue() == player) {
                return true;
            }
            return false;
        case 3: // Middle left
            //456
            if (state[4].getValue() == player && state[5].getValue() == player) {
                return true;
            }
            //147
            if (state[0].getValue() == player && state[6].getValue() == player) {
                return true;
            }
            return false;
        case 4: //Middle middle
            //456
            if (state[3].getValue() == player && state[5].getValue() == player) {
                return true;
            }
            //258
            if (state[1].getValue() == player && state[7].getValue() == player) {
                return true;
            }
            //159
            if (state[0].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            //357
            if (state[2].getValue() == player && state[6].getValue() == player) {
                return true;
            }
            return false;
        case 5: //Middle right
            //456
            if (state[3].getValue() == player && state[4].getValue() == player) {
                return true;
            }
            //369
            if (state[2].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            return false;
        case 6: //Bottom left
            //147
            if (state[0].getValue() == player && state[3].getValue() == player) {
                return true;
            }
            //789
            if (state[7].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            //753
            if (state[4].getValue() == player && state[2].getValue() == player) {
                return true;
            }
            return false;
        case 7: //Bottom middle
            //789
            if (state[6].getValue() == player && state[8].getValue() == player) {
                return true;
            }
            //852
            if (state[4].getValue() == player && state[1].getValue() == player) {
                return true;
            }
            return false;
        case 8: //Bottom right
            //369
            if (state[2].getValue() == player && state[5].getValue() == player) {
                return true;
            }
            //789
            if (state[6].getValue() == player && state[7].getValue() == player) {
                return true;
            }
            //159
            if (state[0].getValue() == player && state[4].getValue() == player) {
                return true;
            }
            return false;
        default:
            return false;
    }

}

bool Board::hasEmptyCells() {
    for(Cell c : state)
    {
        if (!c.isTaken()) {
            return true;
        }
    }
    return false;    
}
