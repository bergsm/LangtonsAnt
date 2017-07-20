/********************************************************************* 
** Author: Shawn Berg
** Date: 6/27/17
** Description: Header file for Ant.cpp
*********************************************************************/

#ifndef PROJECT1_ANT_HPP
#define PROJECT1_ANT_HPP

#include <iostream>
#include "Board.hpp"

enum direction {N, E, S, W};

class Ant
{
private:
    // Member Variables
    //char** gameBoard;

    Board* currentBoard;

    int stepsRem;
    direction currentDirection;
    int antPosX;
    int antPosY;
    char currentSpace;
    char lastSpace;


public:
    // Overload Constructor
    Ant(int, int, int, Board*);


    // Default Constructor
    Ant();


    // Destructor
    ~Ant();

    // Getters
    int getAntPosX();
    int getAntPosY();
    direction getAntDir();
    char getCurrentSpace();
    char getLastSpace();
    int getAntStepsRem();


    // Setters
    void setAntPosX(int);
    void setAntPosY(int);
    void setAntDir(direction);
    void setCurrentSpace(char);
    void setAntStepsRem(int);


    // Methods
    void antTurn();
    void antMove();
};


#endif //PROJECT1_ANT_HPP
