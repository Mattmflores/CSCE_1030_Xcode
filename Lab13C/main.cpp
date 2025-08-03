/*
Author:      Matt Flores (YourEmail@my.unt.edu)
Date:        July 10, 2025
Instructor:  [Your Instructor's Name]
Description: This program demonstrates the use of pointers
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int myInt;
    int* iptr1;
    int* iptr2;

    string myStr;
    string* sptr;

    // Assign the address of myInt to iptr1
    iptr1 = &myInt;

    // Assign the value of iptr1 to iptr2
    iptr2 = iptr1;

    // Assign the address of myStr to sptr
    sptr = &myStr;

    // Prompt for and read an integer using iptr1
    cout << "Enter an integer: ";
    cin >> *iptr1;

    // Clear newline left in input buffer after integer input
    cin.ignore();

    // Prompt for and read a sentence using sptr
    cout << "Enter a sentence: ";
    getline(cin, *sptr);

    // Output the values using iptr2 and sptr
    cout << "Your integer = " << *iptr2 << endl;
    cout << "Your sentence = " << *sptr << endl;

    return 0;
}

