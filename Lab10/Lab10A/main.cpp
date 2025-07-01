/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-30-2025
Instructor: Dr. Amar M. Maharjan
Description: Compares user integer with random integer using functions
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

/*
Function: getRandom
Parameters: nil
Return: a random integer from 0 to 100 inclusive
Description: This function generates a seeded random integer.
*/
int getRandom()
{
    //generate a seeded random number
    srand(static_cast<unsigned int>(time(0)));
    //between 1 and 100, inclusive
    //return the random number
    return rand() % 101;
}

/*
Function: compare
Parameters: an integer representing user's guess
Return: nil
Description: Outputs message based on how user's guess
 compares to random integer.
*/
void compare(int guess)
{
    //call getRandom()
    const int num_random = getRandom();
    string guess_compared_random;
    //compare guess with the returned random number
    guess_compared_random = guess > num_random ? "higher" : num_random == guess ? "equal" : "lower";
    //inform user what the random number was
    cout<<"Random number was "<<num_random<<". ";
    //and whether it was greater than, less than or equal to guess
    cout<<"Your guess was "<<guess_compared_random<<"."<<endl;
}


int main()
{
    int guess;
    //get the value of guess from the user
    cout<<"Enter your guess: ";
    cin>>guess;
    //call compare and pass guess as parameter
    compare(guess);
    return 0;
}

