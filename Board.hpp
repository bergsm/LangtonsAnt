/********************************************************************* 
** Author: Shawn Berg
** Date: 7/4/17
** Description: Header file for Board.cpp
*********************************************************************/

#ifndef PROJECT1_BOARD_HPP
#define PROJECT1_BOARD_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>


class Board
{
private:
    // Member Variables
    char** board;
    int rows;
    int columns;

public:
    // Overload Constructor
    Board(int, int);

    // Default Constructor
    Board();

    // Destructor
    ~Board();

    // Getters
    int getRows();
    int getColumns();
    char** getBoard();

    // Setters
    void setRows(int);
    void setColumns(int);
    void setSpace(int, int, char);


    // Methods
    void print(int, int);

};


#endif //PROJECT1_BOARD_HPP
