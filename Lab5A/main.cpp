/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-05-2025
Instructor: Dr. Amar M. Maharjan
Description: Compares a random number to a user inputted value between 100 and 200
*/

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <ctime>
#include <string>
using namespace std;

int main() {
    // Declare variables
    int numInput; // User inputted value that should be within range
    int numRandom; // Random value to compare user input to
    enum Equality {LESS_THAN, EQUAL_TO, GREATER_THAN}; // States of comparison for user input and random number
    Equality inputComparedToRandom;
    const int lowerBound = 100, upperBound = 200;
    
    // Seed random number to generate unique number each time progran is run
    srand(static_cast<unsigned int>(time(0)));
    
    // Prompt user for number between 100-200
    printf("Enter an integer between 100 and 200, inclusive: "); scanf(" %d", &numInput);
    
    /*
     Check if user value is within range
     Display an error message if not
     Otherwise output message indicating how the user value compares to the random number
    */
    if ((numInput < lowerBound) || (numInput > upperBound)) {
        printf("Number is outside the range \n");
    }
    else {
        numRandom = (rand() % (lowerBound + 1)) + lowerBound; // Generates random number within range
        
        printf("Random number: %d \n", numRandom);
        
        inputComparedToRandom = numInput == numRandom ? EQUAL_TO : numInput > numRandom ? GREATER_THAN : LESS_THAN;
        
        switch (inputComparedToRandom) {
            case EQUAL_TO:
                printf("Entered number is equal to the random number. \n");
                break;
            case GREATER_THAN:
                printf("Entered number is greater than the random number. \n");
                break;
            case LESS_THAN:
                printf("Entered number is less than the random number. \n");
                break;
            default:
                break;
        }
    }
    
    return 0;
}
