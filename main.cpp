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
            if(b.hasWinner(choice-1, currentPlayer)) {
                b.printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                isFinished = true;
            }
            char tmp = currentPlayer;
            currentPlayer = nextPlayer;
            nextPlayer = tmp;
        } else {
            cout << "Wrong choice! Retry.." << endl;
        }
        
    }
    
    
    return 0;
}
