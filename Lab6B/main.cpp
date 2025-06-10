/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-09-2025
Instructor: Dr. Amar M. Maharjan
Description: Computes simple arithmetic based on two user integer inputs
*/

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <typeinfo>
using namespace std;

int main() {
    enum Operation {Multiply='M', Add='A', Difference='D'}; // the operations
    int result; // result of operation
    int num1, num2; // integers to perform operation on
    Operation my_operation;
    char choice;
    bool validChoice;
    
    cout << "Enter two integers: "; cin >> num1 >> num2;
    
    do {
        // prompt for the value of choice
        // to select one of the operations
        cout << "Enter 'M' to multiply, 'A' to add and 'D' for absolute difference: "; cin >> choice;
        
        // cast the user entered character to the switch based on my_operation
        my_operation = static_cast<Operation>(toupper(choice));
        
        // Validate user choice
        validChoice = my_operation == Multiply || my_operation == Add || my_operation == Difference;
        
        switch (my_operation) {
            case Multiply:
                result = num1 * num2;
                break;
            case Add:
                result = num1 + num2;
                break;
            case Difference:
                result = abs(num1 - num2);
                break;
            default:
                cout << "Not a valid choice. Please try again" << endl;
                break;
        }
    } while (!validChoice); // Loops if user choice does not conform to type Operation
    
    cout << "The result of the operation is " << result << "." << endl;
    
    return 0;
}
