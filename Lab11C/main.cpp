/*
   Author:      Matthew Flores (matthewflores10@my.unt.edu)
   Date:        07-11-2025
   Instructor:  Dr. Amar M. Maharjan
   Description: This program reads a list of numbers from 'unsorted.dat',
                stores them in an array,
                sorts them using mySort(),
                and writes the sorted values to 'sorted.dat'.
*/

#include <iostream>
#include <fstream>
using namespace std;

// Function: mySort
// Parameters: array of doubles, and the size of the array
// Return: void
// Description: Sorts the array in ascending order
void mySort(double arr[], const int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    ifstream inFile("unsorted.dat");
    ofstream outFile("sorted.dat");

    // Check for input file error
    if (!inFile) {
        cout << "Error: Cannot open input file 'unsorted.dat'.\n";
        return 1;
    }

    double numbers[100];
    int count = 0;

    // Read numbers into the array
    while (inFile >> numbers[count]) {
        count++;
        if (count >= 100) break;
    }

    inFile.close();

    // Sort the array
    mySort(numbers, count);

    // Check for output file error
    if (!outFile) {
        cout << "Error: Cannot open output file 'sorted.dat'.\n";
        return 1;
    }

    // Write sorted numbers to the file
    for (int i = 0; i < count; ++i) {
        outFile << numbers[i] << endl;
    }

    outFile.close();

    return 0;
}

