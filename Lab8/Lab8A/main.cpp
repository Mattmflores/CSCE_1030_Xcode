/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-24-2025
Instructor: Dr. Amar M. Maharjan
Description: Prints 5 randomly generated capital alpha letters
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
    int outputArray[5];
    
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < 5; ++i) {
        outputArray[i] = (rand() % 25) + 65;
    }
    
    for (int i = 0; i < 5; ++i) {
        printf("%c", outputArray[i]);
    }
    
    cout << endl;
    
    return 0;
}
