/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 05-29-2025
Instructor: Dr. Amar M. Maharjan
Description: A program that computes in feet the distance traveled by an object based on a user's input in seconds
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Declare variables
    float time, distance;
    const int acceleration = 32;

    // Prompt user for time input
    cout << "Enter time in seconds: "; cin >> time;

    // Compute distnace based on input
    distance = (acceleration * pow(time,2)) / 2;

    // Set result to display to 3 decimals points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    // Display distance
    cout << "Total distance traveled by an object after free fall = " << distance << " feet." << endl;
    return 0;
}
