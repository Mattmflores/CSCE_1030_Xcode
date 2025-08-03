/*
 Author:      Matthew Flores (matthewflores10@my.unt.edu)
 Date:        07-15-2025
 Instructor:  Dr. Amar M. Maharjan
 Description: Uses Dynamic Arrays to compute
              minimum values
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


/*
 Function:    computeMin
 Parameters:  A double representing dynamic array.
              An integer representing size of the array.
 Return:      A double determined to be the minimum from the array
 Description: Computes minimum from dynamic array.
*/
double computeMin(double* arr, int sizeArray)
{
    double min = *(arr);
    
    for (int i = 1; i < sizeArray; ++i)
    {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    
    return min;
}

int main()
{
    int ARRAY_SIZE;
    
    // Prompt for array size
    cout << "Enter the size of the array: ";
    cin >> ARRAY_SIZE;
    
    double *numlist = new double[ARRAY_SIZE];
    

    // Read values into array
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> *(numlist + i); // or numlist[i]
    }

    // Compute minimum
    double minimum = computeMin(numlist, ARRAY_SIZE);

    // Write to file
    ofstream outfile("outmin.txt");
    if (!outfile) {
        cerr << "Error opening output file.\n";
        delete[] numlist;
        return 1;
    }

    outfile << fixed << setprecision(2);
    outfile << "The minimum value is " << minimum << "." << endl;

    // Cleanup
    outfile.close();
    delete[] numlist;

    return 0;
}
