/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-26-2025
Instructor: Dr. Amar M. Maharjan
Description: Compares two strings and outputs message
 based on result
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str1[50], str2[50];
    
    strcpy(str1, "We are completing Lab9 today.");
    
    cout << "Enter a phrase with more than one word: ";
    cin.getline(str2, 50);
    
    int str1_length = static_cast<int>(strlen(str1)); // length of string being compared to
    int str2_length = static_cast<int>(strlen(str2)); // lenght of user inputted string
    
    // Compare strings based on length
    if (str1_length == str2_length)
    {
        cout << "The C-strings are the same length." << endl;
        
        // Compare strings based on characters
        if (strcmp(str1, str2) == 0)
        {
            cout << "The two C-strings are the same." << endl;
        }
        else {
            cout << "The two C-strings are NOT the same." << endl;
        }
    }
    else {
        cout << "The C-strings are not the same length and must be diferent words." << endl;
        return 0;
    }
    
    return 0;
}
