#include "includes/Board.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    bool isFinished = false;
    char currentPlayer = 'O';
    char nextPlayer = 'X';

    cout << "Player 'O' starts" << endl;
    Board b;

    while(!isFinished){
        int choice;
        b.printBoard();
        cout << "Player " << currentPlayer << ", make your move.. Enter the cell number where you wanna be" << endl;
        cin >> choice;
        if(b.setCellValue(choice-1, currentPlayer)) {
            //Has the player won?
            char tmp = currentPlayer;
            currentPlayer = nextPlayer;
            nextPlayer = tmp;
        }
    }
    
    
    return 0;
}
