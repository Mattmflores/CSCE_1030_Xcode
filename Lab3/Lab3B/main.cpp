/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 05-29-2025
Instructor: Dr. Amar M. Maharjan
Description: A program to showcase functions from the math library
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Declare variables for user to input
    double x, y, z;

    // Prompt user for variable values
    cout << "Enter a value for x: "; cin >> x;
    cout << "Enter a value for y: "; cin >> y;
    cout << "Enter a value for z: "; cin >> z;

    // Display computed values
    cout << "Value of x^(y^z) = " << pow(x,pow(y,z)) << endl;
    cout << "Absolute value of y = " << fabs(y) << endl;
    cout << "Square root of (xy)^z = " << sqrt(pow(x * y,z)) << endl;
    return 0;
}
