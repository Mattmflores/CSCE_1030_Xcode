/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-03-2025
Instructor: Dr. Amar M. Maharjan
Description: Computes the bonus for an employee based on a rate between 5 and 15
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    string name;
    double salary, bonus;
    int rate;
    
    // Prompt user for values
    cout << "Enter employee name: "; getline(cin, name);
    cout << "Enter salary: $"; cin >> salary;
    
    // Prompt and validate rate
    do {
        cout << "Enter rate of bonus: "; cin >> rate;
        if ((rate < 5) || (rate > 15)) {
            cout << "Percentage Bonus Rate must be between 5 and 15" << endl;
        }
    }
    while ((rate < 5) || (rate > 15));
    
    // Compute bonus
    bonus = salary * (static_cast<double>(rate) / 100);
    
    // Display employee name and bonus
    cout << name << " earned a bonus of $" << fixed << setprecision(2) << bonus << endl;
    
    return 0;
}
