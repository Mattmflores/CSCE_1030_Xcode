/*
   Author:      Matthew Flores (matthewflores10@my.unt.edu)
   Date:        07-11-2025
   Instructor:  Dr. Amar M. Maharjan
   Description: This program reads an input file using get(),
                and writes to an output file using put().
*/

#include <iostream>
#include <fstream>
#include <cstdlib>  // for exit()
using namespace std;

int main() {
    char c;
    ifstream inStrm;  // declaration of the stream of type input
    ofstream outStrm; // declaration of the stream of type output

    char inputFile[50];
    char outputFile[50];

    // read input file name
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    inStrm.open(inputFile);

    // check if input stream is successfully opened
    if (!inStrm.is_open()) {
        cout << "Unable to open input file " << inputFile << endl;
        exit(EXIT_FAILURE);
    }

    // read output file name
    cout << "Enter the name of the output file: ";
    cin >> outputFile;
    outStrm.open(outputFile);

    if (!outStrm.is_open()) {
        cout << "Unable to open output file " << outputFile << endl;
        exit(EXIT_FAILURE);  // exit if cannot open file
    }

    // read all characters one-by-one to end of file using get()
    inStrm.get(c);  // initial read
    while (!inStrm.eof()) {
        outStrm.put(c);  // write to output file
        inStrm.get(c);   // read next character
    }

    inStrm.close();  // close the input file
    outStrm.close(); // close the output file

    return 0;
}
