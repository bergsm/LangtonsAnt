/********************************************************************* 
** Author: Shawn Berg
** Date: 7/6/17
** Description: Menu for programs
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "input_validation.hpp"

using namespace std;

int menu(bool firstTime)
{

    int selection = 0;
    bool inputValid = false;

    // Menu
    cout << "Menu" << endl << endl;

    // 1) Start program
    if (firstTime == true)
        cout << "1) Start Program" << endl << endl;

    // 2) Change steps if firstTime = false
    if (firstTime == false)
        cout << "1) Change number of steps" << endl << endl;

    // 3) Change start location if firstTime = false
    if (firstTime == false)
        cout << "2) Change start location of ant" << endl << endl;

    // 4) Change size of board if firstTime = false
    if (firstTime == false)
        cout << "3) Change size of board" << endl << endl;

    // 5) Play again with same values if firstTime = false
    if (firstTime == false)
        cout << "4) Play again" << endl << endl;

    // 6) Quit
    if (firstTime == true)
        cout << "2) Quit" << endl << endl;
    else
        cout << "5) Quit" << endl << endl;

    // User input
    //while (inputValid == false)
    //{
        cout << "Select an option and press [enter]" << endl;
        cin >> selection;
        //inputValid = inputValid(selection);
    //}

    return selection;
}
