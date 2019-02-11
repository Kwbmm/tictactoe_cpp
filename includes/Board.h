#include <string>

class Board
{
private:
    static const int boardSize = 9;
    char state [boardSize] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::string printCell(int index);
public:
  void printBoard();
  bool isCellFree(int cellNumber);
};