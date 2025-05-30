/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 05-29-2025
Instructor: Dr. Amar M. Maharjan
Description: A program that computes an average and product based on four user inputs
*/

#include <iostream>
using namespace std;

int main() {
    // Declare variables
    float first, second, third, fourth;
    float product, average; // computed variables

    // Prompt user for four numbers
    cout << "Enter first number: "; cin >> first;
    cout << "Enter second number: "; cin >> second;
    cout << "Enter third number: "; cin >> third;
    cout << "Enter fourth number: "; cin >> fourth;

    // Compute product and average based on user inputs
    product = first * second * third * fourth;
    average = (first + second + third + fourth)/4;

    // set results to display with 2 decimals points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Display results
    cout << "Product = " << product << endl;
    cout << "Average = " << average << endl;
    return 0;
}
