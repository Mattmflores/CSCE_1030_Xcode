/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-09-2025
Instructor: Dr. Amar M. Maharjan
Description: Computes simple arithmetic based on two user integer inputs
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    string userInput; // user inputted value
    const string vowels = "AEIOU"; // used to validate if string contains vowel
    int totalASCIISum = 0;
    int numVowels = 0;
    int numConsonants = 0;
    int numWords = 0;
    const char whitespace = 32; // ASCII value for space
    
    // Prompt user for string and store
    printf("Enter string: "); getline(cin, userInput);
    
    // Loop through string one character at at time
    for (int i = 0; i < userInput.size(); ++i) {
        // Check if character is alphabetical letter
        if (isalpha(userInput.at(i))) {
            if (vowels.find(toupper(userInput.at(i))) != string::npos) { // if character is found in string of vowels
                ++numVowels; // increment number of vowels
            }
            else {
                ++numConsonants; // otherwise increment number of consonants
            }
        }
        /*
         Count number of words by checking if character is whitespace
         if not, verify if character is first in string or preceeded by whitespace
        */
        if (userInput.at(i) != whitespace) {
            if (i == 0 || userInput.at(i - 1) == whitespace) {
                ++numWords;
            }
        }
        
        totalASCIISum += userInput.at(i); // Current character ASCII value added to sum
    }
    
    printf("Number of vowels: %d\n", numVowels);
    printf("Number of consonants: %d\n", numConsonants);
    printf("Total ASCII sum of input characters: %d\n", totalASCIISum);
    printf("Number of words: %d\n", numWords);
    
    return 0;
}
