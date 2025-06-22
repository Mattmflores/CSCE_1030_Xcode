/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-12-2025
Instructor: Dr. Amar M. Maharjan
Description: Formats user inputted string to valid sentence structure
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cctype>
using namespace std;

int main() {
    // Declare variables
    string sentence;
    bool correctFormat = true; // Becomes false if sentence contains errors
    
    // Prompt for sentence
    printf("Enter string:"); getline(cin, sentence);
    
    if (!isalpha(sentence[0])) { // If sentence does not begin with alphabetical letter...
        correctFormat = false;
        printf("The first character must be an alphabet.\n");
    }
    else {
        if (sentence[0] != toupper(sentence[0])) { // If sentence does not beging with capital letter...
            correctFormat = false;
            printf("The first character must be an uppercase alphabet.\n");
            sentence[0] = toupper(sentence[0]);
        }
    }
    
    if (sentence[sentence.size() - 1] != '.') { // If sentence does not end in a period...
        correctFormat = false;
        printf("The last character must be a period.\n");
        sentence.insert(sentence.size(), ".");
    }
    
    if (correctFormat) printf("There are no errors in the string.\n");
    
    // Output sentence modified by any errors
    cout << sentence << endl;
    
    return 0;
}
