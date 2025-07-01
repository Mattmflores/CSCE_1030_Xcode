/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-30-2025
Instructor: Dr. Amar M. Maharjan
Description: Generates random array and outputs values
 along with minimum
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

// Global constant
const int SIZE = 10;

/*
Function: minArray
Parameters: An immutable array used to determine minimum.
Return: The minimum from the parameter array
Description: This function locates and returns the minimum value
 from an integer array.
*/
int minArray(const int array[]) {
    // Set current minimum to initial array value
    int min = array[0];
    for (int i = 0; i < SIZE; ++i) {
        // Set new minimum to current element if smaller than current minimum
        if (array[i] < min) min = array[i];
    }
    // Return minimum value from array
    return min;
}

int main() {
    int array[SIZE];
    // Seed random numbers
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate random numbers for each element in array
    for (int i = 0; i < SIZE; ++i) {
        array[i] = (rand() % 51) + 50;
        // Outpus randomly generated numbers
        printf("Random #%d:%d\n",i+1,array[i]);
    }
    // Display minimum from array holding randomly genereated elements
    printf("Minimum:%d\n",minArray(array));
    return 0;
}
