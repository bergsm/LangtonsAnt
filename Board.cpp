/********************************************************************* 
** Author: Shawn Berg
** Date: 7/4/17
** Description: Keeps track of the board for Langton's Ant
*********************************************************************/

#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board()
{}

Board::Board(int rows, int columns)
{
    // dynamically create new board
    board = new char*[rows];
    for (int i=0; i<rows; i++)
        board[i] = new char[columns];

    // create seed for randomly filling board
    unsigned seed;
    seed = time(0);
    srand(seed);
    int spaceDec = 0;

    // Random fill with black "#" and white "_"
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            board[i][j] = ' ';
        }
    }
}

Board::~Board()
{
    // free memory
    for (int i=0; i<rows; i++)
    {
        delete [] board[i];
    }
    delete [] board;
}


int Board::getRows()
{
    return rows;
}

int Board::getColumns()
{
    return columns;
}

char** Board::getBoard()
{
    return board;
}


void Board::setRows(int newRows)
{
    rows = newRows;
}

void Board::setColumns(int newColumns)
{
    columns = newColumns;
}

void Board::setSpace(int X, int Y, char c)
{
    board[X][Y] = c;
}


void Board::print(int antPosX, int antPosY)
{
    // Place ant on board
    board[antPosX][antPosY] = '@';

    // print board
    for (int i=0; i<columns; i++)
    {
        for (int j=0; j<rows; j++)
        {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
