/*
Author: Matthew Flores (matthew.flores10@my.unt.edu)
Date: 05-27-25
Instructor: Dr. Amar M. Maharjan
Description: A program to run the module from Lab2B.
This program takes in the dimensions of a cylinder
inputted from a user to calculate the surface area.
*/
#include <iostream>

using namespace std;

int main() {
// variable declarations
int radius;
int height;
// read inputs for radius and height
cout << "Enter radius(cm) of cylinder: ";
cin >> radius;
cout << "Enter height(cm) of cylinder: ";
cin >> height;
// Compute surface area of a cylinder and print the value.
cout << "Surface area(cm^2) of cylinder is ";
cout << 3.14159 * radius * (radius + height);
cout << endl;
return 0;
}
