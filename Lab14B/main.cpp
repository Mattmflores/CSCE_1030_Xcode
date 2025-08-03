/*
 Author:      Matthew Flores (matthewflores10@my.unt.edu)
 Date:        07-15-2025
 Instructor:  Dr. Amar M. Maharjan
 Description: Computes average salary of employees using structs
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// Define Employee struct
struct Employee
{
    string name;
    double salary;
};

int main()
{
    ifstream infile("data.dat");
    
    if (!infile)
    {
        cerr << "Error: Could not open file data.dat\n";
        return 1;
    }

    Employee* emp;
    double sum = 0.0;
    int count = 0;
    string line;

    while (getline(infile, line))
    {
        // Create dynamic struct
        emp = new Employee;

        // Parse line
        stringstream ss(line);
        string salaryStr;

        getline(ss, emp->name, ',');
        getline(ss, salaryStr);
        emp->salary = stod(salaryStr);

        // Accumulate salary and count
        sum += emp->salary;
        count++;

        // Free memory
        delete emp;
    }

    infile.close();

    if (count > 0)
    {
        double average = sum / count;
        cout << fixed << setprecision(2);
        cout << "Average salary: $" << average << endl;
    } else {
        cout << "No data found in file.\n";
    }

    return 0;
}

