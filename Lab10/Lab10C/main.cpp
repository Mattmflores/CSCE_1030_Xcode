/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-30-2025
Instructor: Dr. Amar M. Maharjan
Description: Computes maximum scores of students
*/

#include <iostream>
using namespace std;

// Global variables
const int COLS = 6; // 6 quiz grades
const int ROWS = 10; // 10 students
void computeMaximum(float grades[][COLS], int num, float maximum[]);
void showArray(float array[], int size);

int main()
{
    float grades[ROWS][COLS]; // 2D array for grades
    float maximum[ROWS]; // array to store maximum grade for each student
    int num; // number of students in the class, must not be more than 10

    cout << "How many students in the class? ";
    cin >> num; // get number of students

    for (int row = 0; row < num; row++)
    {
        // enters 6 quiz grades for each student
        for (int col = 0; col < COLS; col++)
        {
            cout << "Enter QUIZ #" << col+1 << " for STUDENT #" << row+1 << ": ";
            cin >> grades[row][col];
        }
    }
    
    //call function computeMaximum
    computeMaximum(grades, num, maximum);
    
    cout << "Student's scores:" << endl;
    for (int row = 0; row < num; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << grades[row][col] << " ";
        }

        cout << endl;
    }

    cout << "The maximum grades:\n";
    //call function showArray
    showArray(maximum, num);
    cout << endl;
    return 0;

}

/*
Function: computeMaximum
Parameters: 2D array represent grades of students,
 number of rows representing number of students,
 array to hold maximum grade found from each student
Return: n/a
Description: Pushes maximum values from grades parameter to maximum parameter
*/
void computeMaximum(float grades[][COLS], int num, float maximum[]) {
    for (int i = 0; i < num; ++i) {
        int maxRow = grades[i][0];
        for (int j = 0; j < COLS; ++j) {
            if (grades[i][j] > maxRow) maxRow = grades[i][j];
        }
        maximum[i] = maxRow;
    }
}

/*
Function: showArray
Parameters: Array to display, number of rows of array
Return: n/a
Description: Outputs values of parameter array separated by space
*/
void showArray(float array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
}
