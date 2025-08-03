/*
   Author:      Matthew Flores (matthewflores10@my.unt.edu)
   Date:        07-11-2025
   Instructor:  Dr. Amar M. Maharjan
   Description: This program reads 3 integers from "data.dat",
                computes the average of each line,
                and writes the result to "average.dat".
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inFile("data.dat");
    ofstream outFile("average.dat");

    // Validate input file opens
    if (!inFile) {
        cout << "Error: Cannot open input file 'data.dat'.\n";
        return 1;
    }
    
    // Validate output file opens
    if (!outFile) {
        cout << "Error: Cannot open output file 'average.dat'.\n";
        return 1;
    }

    // Compute Average
    int num1, num2, num3;
    while (inFile >> num1 >> num2 >> num3) {
        double average = (num1 + num2 + num3) / 3.0;
        outFile << fixed << setprecision(2) << average << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}

