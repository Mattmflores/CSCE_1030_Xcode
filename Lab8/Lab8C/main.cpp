/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-24-2025
Instructor: Dr. Amar M. Maharjan
Description: Outputs int values above average based on user inputs
*/

#include <iostream>
using namespace std;

int main() {
    char arr[] = {'b','f','a','z','m','g','q','t'};
    for (int i = 0; i < 8; ++i)
    {
        for (int j = i + 1; j < 8; ++j)
        {
            /*
             Write an if-else block here:
             If element at index i is less than element at index j
             swap values of element at indicies i and j
             */
            if (arr[i] < arr[j])
            {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < 8; ++i)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    
    return 0;
}
