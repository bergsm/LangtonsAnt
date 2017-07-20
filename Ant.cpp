/********************************************************************* 
** Author: Shawn Berg
** Date: 6/27/17
** Description: This class holds information for the ant
*********************************************************************/

#include <iostream>
#include "Ant.hpp"

using namespace std;

Ant::Ant()
{}

Ant::Ant(int startPosX, int startPosY, int stepsIn, Board* inputBoard)
{

    currentBoard = inputBoard;
    antPosX = startPosX;
    antPosY = startPosY;
    stepsRem = stepsIn;
    currentDirection = N;
    currentSpace = '#';//TODO start random space?
    lastSpace = '#'; //TODO random space?
}

Ant::~Ant()
{

}

int Ant::getAntPosX()
{
    return antPosX;
}

int Ant::getAntPosY()
{
    return antPosY;
}

direction Ant::getAntDir()
{
    return currentDirection;
}

char Ant::getCurrentSpace()
{
    return currentSpace;
}

char Ant::getLastSpace()
{
    return lastSpace;
}

int Ant::getAntStepsRem()
{
    return stepsRem;
}

void Ant::setAntPosX(int newAntPosX)
{
    antPosX = newAntPosX;
}

void Ant::setAntPosY(int newAntPosY)
{
    antPosY = newAntPosY;
}

void Ant::setAntDir(direction newDirection)
{
    currentDirection = newDirection;
}

void Ant::setCurrentSpace(char newCurrentSpace)
{
    currentSpace = newCurrentSpace;
}

void Ant::setAntStepsRem(int newStepsRem)
{
    stepsRem = newStepsRem;
}

void Ant::antTurn()
{
    switch (currentDirection)
    {
        case N:
            if (currentSpace == '#')
            {
                currentDirection = W;
            }

            if (currentSpace == ' ')
            {
                currentDirection = E;
            }
            break;

        case E:
            if (currentSpace == '#')
            {
                currentDirection = N;
            }

            if (currentSpace == ' ')
            {
                currentDirection = S;
            }
            break;

        case S:
            if (currentSpace == '#')
            {
                currentDirection = E;
            }

            if (currentSpace == ' ')
            {
                currentDirection = W;
            }
            break;

        case W:
            if (currentSpace == '#')
            {
                currentDirection = S;
            }

            if (currentSpace == ' ')
            {
                currentDirection = N;
            }
            break;
    }
}

void Ant::antMove()
{
    bool antMoved = false;


    // Switch for direction facing
    while (antMoved == false)
    {
        switch (currentDirection)
        {
            case N: // North
                if (antPosY - 1 >= 0)
                {
                    lastSpace = currentSpace; //update space ant will be leaving
                    currentSpace = currentBoard->getBoard()[antPosX][antPosY - 1]; //update space ant will be moving to

                    antPosY -= 1; // move ant

                    stepsRem -= 1; // decrease steps
                    antMoved = true;
                }
                else if (currentSpace == '#')
                    currentDirection = W;
                else if (currentSpace == ' ')
                    currentDirection = E;
                break;

            case E: // East
                if (antPosX + 1 < currentBoard->getRows())
                {
                    lastSpace = currentSpace;
                    currentSpace = currentBoard->getBoard()[antPosX + 1][antPosY];

                    antPosX += 1;

                    stepsRem -= 1;
                    antMoved = true;
                }
                else if (currentSpace == '#')
                    currentDirection = N;
                else if (currentSpace == ' ')
                    currentDirection = S;
                break;

            case S: // South
                if (antPosY + 1 < currentBoard->getColumns())
                {
                    lastSpace = currentSpace;
                    currentSpace = currentBoard->getBoard()[antPosX][antPosY + 1];

                    antPosY += 1;

                    stepsRem -= 1;
                    antMoved = true;
                }
                else if (currentSpace == '#')
                    currentDirection = E;
                else if (currentSpace == ' ')
                    currentDirection = W;
                break;

            case W: // West
                if (antPosX - 1 >= 0)
                {
                    lastSpace = currentSpace;
                    currentSpace = currentBoard->getBoard()[antPosX - 1][antPosY];

                    antPosX -= 1;

                    stepsRem -= 1;
                    antMoved = true;
                }
                else if (currentSpace == '#')
                    currentDirection = S;
                else if (currentSpace == ' ')
                    currentDirection = N;
                break;
        }
    }

}
