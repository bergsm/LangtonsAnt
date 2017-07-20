/********************************************************************* 
** Author: Shawn Berg
** Date: 6/27/17
** Description: A simulation of Langton's ant
*********************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "input_validation.hpp"
#include "menu.hpp"

using namespace std;

int main()
{
    bool firstTime = true;
    int userWidth;
    int userHeight;
    int userSteps;
    int antPosX;
    int antPosY;
    // TODO make seed apart of main?

    cout << "Welcome to Langton's Ant!" << endl << endl;

    if (firstTime == true)
    {
        bool userReady = false;

        while (userReady == false)
        {
            switch (menu(firstTime))
            {
                case 1: //Start Program
                    cout << "Enter the width of the board between 1 and 80" << endl;
                    userWidth = inputValid(1, 80);

                    cout << "Enter the height of the board between 1 and 80" << endl;
                    userHeight = inputValid(1, 80);

                    cout << "Enter the number of steps for the ant." << endl;
                    userSteps = inputValid(1, 999999);

                    //starting location for ant //TODO random starting location
                    cout << "Enter start location for ant" << endl;
                    cout << "X coordinate? (0 - " << userWidth << ")"
                         << endl;
                    antPosX = inputValid(0, userWidth - 1);

                    cout << "Y coordinate? (0 - " << userHeight << ")"
                         << endl;
                    antPosY = inputValid(0, userHeight - 1);

                    userReady = true;
                    break;

                case 2: // Quit
                    return 0;

                default:
                    cout << "You did not enter a valid option." << endl;
                    break;
            }
        }

        // create board
        Board firstBoard(userWidth, userHeight);
        firstBoard.setRows(userWidth);
        firstBoard.setColumns(userHeight);

        // create ant
        Ant firstAnt(antPosX, antPosY, userSteps, &firstBoard);

        // run game
        while(firstAnt.getAntStepsRem()>0)
        {
            // Print Board
            firstBoard.print(firstAnt.getAntPosX(), firstAnt.getAntPosY());

            // Turn Ant
            firstAnt.antTurn();

            // Change space ant is leaving
            if (firstAnt.getCurrentSpace() == '#')
            {
                firstBoard.setSpace(firstAnt.getAntPosX(),
                                    firstAnt.getAntPosY(), ' ');
            }
            if (firstAnt.getCurrentSpace() == ' ')
            {
                firstBoard.setSpace(firstAnt.getAntPosX(), firstAnt.getAntPosY(), '#');
            }

            // Move ant
            firstAnt.antMove();
        }

        //print final
        firstBoard.print(firstAnt.getAntPosX(), firstAnt.getAntPosY());

        firstTime = false;

        // TODO play again?

    }

    while (firstTime == false)
    {
        bool userReady = false;
        bool antInput = false;

        while(userReady == false)
        {
            switch (menu(firstTime))
            {
                case 1: // Change number of steps
                    cout << "Number of steps for the ant to take." << endl;
                    userSteps = inputValid(1, 999999);
                    break;

                case 2: // Change start location
                    cout << "Enter start location for ant" << endl;
                    cout << "X coordinate? (0 - " << userWidth << ")" << endl;
                    antPosX = inputValid(0, userWidth - 1);

                    cout << "Y coordinate? (0 - " << userHeight << ")" << endl;
                    antPosY = inputValid(0, userHeight - 1);

                    antInput = true;
                    break;

                case 3: // Change size of board
                    cout << "Enter width of the board between 1 and 80" << endl;
                    userWidth = inputValid(1, 80);

                    cout << "Enter height of the board between 1 and 80" << endl;
                    userHeight = inputValid(1, 80);
                    break;

                case 4: // play again
                    if ((antPosX > userWidth || antPosX < 0) || (antPosY > userHeight || antPosY < 0))
                    {
                        cout << "Error. Ant not on board." << endl;
                    }
                    else
                    {
                        userReady = true;
                    }
                    break;

                case 5: // Quit
                    return 0;

                default:
                    cout << "You did not enter a valid option." << endl;
                    break;
            }
        }

        // create new Board
        Board newBoard(userWidth, userHeight); //TODO make seed apart of main?
        newBoard.setRows(userWidth);
        newBoard.setColumns(userHeight);

        // create new Ant
        if (antInput == false)
        {
            antPosX = userWidth/2;
            antPosY = userHeight/2;
        }


        Ant newAnt(antPosX, antPosY, userSteps, &newBoard);

        // Play game
        while (newAnt.getAntStepsRem()>0)
        {
            newBoard.print(newAnt.getAntPosX(), newAnt.getAntPosY());
            newAnt.antTurn();

            if (newAnt.getCurrentSpace() == '#')
            {
                newBoard.setSpace(newAnt.getAntPosX(), newAnt.getAntPosY(), ' ');
            }
            if (newAnt.getCurrentSpace() == ' ')
            {
                newBoard.setSpace(newAnt.getAntPosX(), newAnt.getAntPosY(), '#');
            }

            newAnt.antMove();
        }

        // print final
        newBoard.print(newAnt.getAntPosX(), newAnt.getAntPosY());

        // TODO play again?
    }

}
