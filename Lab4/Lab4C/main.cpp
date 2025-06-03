/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-03-2025
Instructor: Dr. Amar M. Maharjan
Description: Outputs and reads user inputs using printf/scanf
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    // Declare variables
    char a, b;
    int c, d;
    double e, f;
    
    // Prompt user for inputs
    printf("Enter character values for a and b: "); scanf(" %c %c", &a, &b);
    printf("Enter integer values for c and d: "); scanf(" %d %d", &c, &d);
    printf("Enter floating point values for e and f: "); scanf(" %lf %lf", &e, &f);
    
    // Display user inputs
    printf("You just entered a:%c b:%c c:%d d:%d e:%lf f:%e \n", a, b, c, d, e, f);
    
    return 0;
}
