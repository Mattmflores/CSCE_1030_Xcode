/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-26-2025
Instructor: Dr. Amar M. Maharjan
Description: Determines and outputs minimum row
 & column values from 2D matrix
*/

#include <iostream>
using namespace std;

int main()
{
    const int ROW_SIZE = 2; // number of rows
    const int COLUMN_SIZE = 5; // number of columns
    int matrix[ROW_SIZE][COLUMN_SIZE]; // 2D array
    int min_row[ROW_SIZE];
    int min_column[COLUMN_SIZE];

    for(int i = 0; i < ROW_SIZE; ++i)
    {
        for (int h = 0; h < COLUMN_SIZE; ++h)
        {
            cout << "Enter data for row#" << i+1 << " and column#" << h+1 << ": ";
            cin >> matrix[i][h]; // read matrix elements
        }
    }

    cout << "You entered:" << endl;
    for(int i = 0; i < ROW_SIZE; ++i)
    {
        for(int h = 0; h < COLUMN_SIZE; ++h)
        {
            cout << matrix[i][h] << "\t";
        }
        cout << endl;
    }
    
    // Nested loop to determine minimum row and column values from matrix
    for(int i = 0; i < ROW_SIZE; ++i)
    {
        int current_min_row = matrix[i][0]; // Sets the current minimum row value to first value in row
        for(int h = 0; h < COLUMN_SIZE; ++h)
        {
            if  (matrix[i][h] < current_min_row) current_min_row = matrix[i][h]; // If true, sets new current minimum row value
            if  (i == ROW_SIZE - 1) min_column[h] = matrix[ROW_SIZE - 1][h] < matrix[0][h] ? matrix[ROW_SIZE - 1][h] : matrix[0][h]; // If loop is in final row, compare to prevous row to obtain minimum column value
        }
        min_row[i] = current_min_row; // apends minimum row value
    }
    
    // Output minimums from rows
    for(int i = 0; i < ROW_SIZE; ++i)
    {
        cout << "Minimum of row " << i + 1 << ": " << min_row[i] << endl;
    }
    // Output minimum from columns
    for(int i = 0; i < COLUMN_SIZE; ++i)
    {
        cout << "Minimum of column " << i + 1 << ": " << min_column[i] << endl;
    }

    return 0;
}

