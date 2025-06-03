/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-03-2025
Instructor: Dr. Amar M. Maharjan
Description: Outputs randomly generated initials
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
    char firstInitial, secondInitial;
    int numOfLettersInAlphabet = 26;
    
    // Seed random number based on time to produce unique number whenever program is run
    srand(static_cast<unsigned int>(time(0)));
    
    firstInitial = (rand() % numOfLettersInAlphabet) + 65; // A-Z in ASCII corresponds to 65-90
    secondInitial = (rand() % numOfLettersInAlphabet) + 65;
    
    // Output results
    printf("Initials are: %c%c \n", firstInitial, secondInitial);
    
    return 0;
}
