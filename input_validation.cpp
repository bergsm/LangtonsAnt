/********************************************************************* 
** Author: Shawn Berg
** Date: 7/6/17
** Description: Validates an input for an integer within a range.
*********************************************************************/

#include <iostream>
#include "input_validation.hpp"

using namespace std;

int inputValid(int min, int max)
{
    int userInput;
    cin >> userInput;

    while (userInput < min || userInput > max)
    {
        cout << "Error. Please enter a number between " << min << " and " << max << "." << endl;
        cin >> userInput;
    }

    return userInput;

}
