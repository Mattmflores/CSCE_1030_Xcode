/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-09-2025
Instructor: Dr. Amar M. Maharjan
Description: Generates two random integers and outputs all even
 values in between along with the cumulative sum
*/

#include <iostream>
#include <ctime>
#include <cstdio>
#include <stdio.h>
using namespace std;

int main() {
    // Seed random numbers to generate unique value each time program is run
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate upper and lower bound random values
    const int numRandom1 = (rand() % 21) + 15; // Generate random number 15-35
    const int numRandom2 = (rand() % 21) + 55; // Generate random number 55-75
    
    // Set even starting and ending positions
    int numStart = (numRandom1 % 2) == 0 ? numRandom1 : numRandom1 + 1; // If lower bound is odd, increment
    int numEnd = (numRandom2 % 2) == 0 ? numRandom2 : numRandom2 - 1; // If upper bound is odd, decrement
    int sum = numStart;
    
    // Output even values between randomly generated integers
    while (numStart <= numEnd) {
        printf("%d\n", numStart);
        numStart += 2;
        if (numStart <= numEnd) sum += numStart;
    }
    
    printf("First random number: %d\n", numRandom1);
    printf("Second random number: %d\n", numRandom2);
    printf("Sum: %d\n", sum);
    
    return 0;
}
