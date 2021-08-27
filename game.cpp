#include <iostream>
#include <string>
using namespace std;

const int ROWS{3};
const int COLS{3};

void rungame();
void initializeBoard(string gameboard[ROWS][COLS]);
void printCurrentBoard(string gameboard[ROWS][COLS]);
void getUserInput(bool xturn, int row, int col, string gameboard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameboard[ROWS][COLS]);
string getWinner(string gameboard[ROWS][COLS]);
bool isBoardFull(string gameboard[ROWS][COLS]);

int main()
{
    rungame();
    return 0;
}
void rungame()
{
    string winner{};
    string board[ROWS][COLS];
    initializeBoard(board);
    printCurrentBoard(board);
    for (int i = 0; i < 9; i++)
    {
        cout << "TIC TAC TOE" << endl;
        //printCurrentBoard(board);
        bool xturn;
        int row, col;
        if (i % 2 == 0)
        {
            xturn = true;

            cout << "Player X's turn" << endl;
            cout << "Row: ";
            cin >> row;
            row -= 1;
            cout << "Col: ";
            cin >> col;
            col -= 1;
            cout << endl;
            bool cellfilled = cellAlreadyOccupied(row, col, board);
            if (cellfilled != true)
            {
                getUserInput(xturn, row, col, board);
            }
            else
            {
                cout << "Warning: That cell is already filled please select another cell" << endl;
                i--;
                continue;
            }
            //printCurrentBoard(board);
            winner = getWinner(board);
            if (winner == "X" || winner == "O")
            {
                break;
            }
        }
        else
        {
            xturn = false;
            cout << "Player O's turn" << endl;
            cout << "Row: ";
            cin >> row;
            row -= 1;
            cout << "Col: ";
            cin >> col;
            col -= 1;
            cout << endl;
            bool cellfilled = cellAlreadyOccupied(row, col, board);
            if (cellfilled != true)
            {
                getUserInput(xturn, row, col, board);
            }
            else
            {
                cout << "Warning: That cell is already filled please select another cell" << endl;
                i--;
                continue;
            }
            //printCurrentBoard(board);
            winner = getWinner(board);
            if (winner == "X" || winner == "O")
            {
                break;
            }
        }
        printCurrentBoard(board);
    }
    cout << "The winner is " << winner << endl;
}
void initializeBoard(string gameboard[ROWS][COLS])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameboard[i][j] = " ";
        }
    }
}
void printCurrentBoard(string gameboard[ROWS][COLS])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
                cout << gameboard[i][j];
            else
                cout << gameboard[i][j] << " | ";
        }
        cout << endl;
    }
}
void getUserInput(bool xturn, int row, int col, string gameboard[ROWS][COLS])
{
    //bool cellstate = cellAlreadyOccupied(row,col,gameboard);
    if (xturn == true)
    {
        gameboard[row][col] = "X";
    }
    else
    {
        gameboard[row][col] = "O";
    }
}
bool cellAlreadyOccupied(int row, int col, string gameboard[ROWS][COLS])
{
    if (gameboard[row][col] != " ")
        return true;
    else
        return false;
}
string getWinner(string gameboard[ROWS][COLS])
{
    for (int i = 0; i < 3; i++)
    {
        if (gameboard[i][0] == gameboard[i][1] && gameboard[i][0] == gameboard[i][2] && gameboard[i][0] != " ")
            return (gameboard[i][0]);
        if (gameboard[0][i] == gameboard[1][i] && gameboard[0][i] == gameboard[2][i] && gameboard[0][i] != " ")
            return (gameboard[1][i]);
    }
    if (gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2] && gameboard[0][0] != " ")
        return (gameboard[1][1]);
    if (gameboard[0][2] == gameboard[1][1] && gameboard[0][2] == gameboard[2][0] && gameboard[0][2] != " ")
        return (gameboard[1][1]);
    return "NO ONE";
}
bool isBoardFull(string gameboard[ROWS][COLS])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameboard[i][j] == " ")
                return false;
        }
    }
    return true;
}
