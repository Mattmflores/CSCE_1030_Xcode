/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-25-2025
Instructor: Dr. Amar M. Maharjan
Description: Outputs salary information of employee
 based on user inputs
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <cctype>
using namespace std;

int main() {
    enum JobRoles { MANAGER = 1, DEVELOPER = 2, TESTER = 3, INTERN = 4};
    string nameEmployee;
    char userContinueChoice;
    int numEmployee = 1; // iterates each time user chooses to continue
    int hoursWorked;
    int userJobChoice;
    double baseSalary = 0.00, netSalary, grossSalary;
    double bonus, tax;
    bool shouldContinue = true; // flips to falase if user chooses not to continue
    bool validName, nameIsEmpty, validHours, validJob; // used to determine if program should continue to next sequence requiring user input
    
    srand(static_cast<unsigned int>(time(0)));
    
    /*
     Loop continues each time user chooses to input new employee
    */
    do {
        printf("Calculating Salary for Employee #%d\n", numEmployee);
        
        ++numEmployee;
        
        /*
         Loop continues until user inputs valid employee name
        */
        do {
            // Prompt user for employee name
            printf("Enter emplyee name (alphabets and spaces only): "); getline(cin, nameEmployee);
            validName = true; // will flip to false if validation fails
            nameIsEmpty = true; // will flip to false if name contains any valid character besides whitespace
            
            // Validate name contains only alpha characters and whitespace
            for (int i = 0; i < nameEmployee.length(); ++i) {
                const char whitespace = 32; // ASCII value for space
                const bool nameContainsInvalidChar = !isalpha(nameEmployee.at(i)) && nameEmployee.at(i) != whitespace;
                const bool shouldCapitalize = (i == 0 && isalpha(nameEmployee.at(i))) || (i != 0 && nameEmployee.at(i - 1) == whitespace && isalpha(nameEmployee.at(i)));
                
                // Fail validation if invalid character found
                if (nameContainsInvalidChar) {
                    validName = false;
                    printf("Invalid name! Use alphabets and spaces only.\n");
                    break;
                }
                
                // Mark as nonempty if valid character found
                if (shouldCapitalize) {
                    nameEmployee[i] = toupper(nameEmployee.at(i));
                    nameIsEmpty = false;
                }
            }
            
            // Fail if only only whitespace
            if (nameIsEmpty) {
                printf("Invalid name! Use alphabets and spaces only.\n");
                validName = false;
            }
            
        } while (!validName || nameIsEmpty);
        
        /*
         Loop continues until user inputs valid number of hours for employee
        */
        do {
            // Prompt user for hours worked
            printf("Enter hours worked this month: "); cin >> hoursWorked;
            
            // Clear buffer if invalid input, will cause loop to retrigger
            if (cin.fail() || hoursWorked < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                printf("Invalid hours input! Restarting entry\n");
                validHours = false;
            }
            // Otherwise mark input valid to exit loop
            else {
                validHours = true;
                cin.ignore(1000, '\n');
            }
        } while (!validHours);
        
        
        /*
         Loop continues until user chooses valid job role of employee
        */
        do {
            // Prompt user for job role of employee
            printf("Select job role: \n1. Manager \n2. Developer \n3. Tester \n4. Intern \n");
            printf("Enter role number: "); cin >> userJobChoice;
            
            // Clear buffer if invalid
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
            validJob = true; // flips to false if default case in userJobChoice hit
            bonus = 100.00; // minimum bonus
            
            // Determine salary of employee based on job role
            switch (userJobChoice) {
                case MANAGER:
                    baseSalary = 5000.00;
                    bonus += rand() % 201;
                    
                    if (hoursWorked - 160 > 0) bonus += (hoursWorked - 160) * 25;
                    break;
                case DEVELOPER:
                    baseSalary = 4000.00;
                    bonus += rand() % 151;
                    
                    if (hoursWorked - 160 > 0) bonus += (hoursWorked - 160) * 20;
                    break;
                case TESTER:
                    baseSalary = 3000.00;
                    bonus += rand() % 101;
                    
                    if (hoursWorked - 160 > 0) bonus += (hoursWorked - 160) * 15;
                    break;
                case INTERN:
                    baseSalary = 1500.00;
                    bonus += rand() % 51;
                    break;
                default:
                    validJob = false;
                    printf("Unknown role encountered. Please enter a valid role\n");
                    break;
            }
            
        } while (!validJob);
        
        /*
         The purpose of the following section of code until the next loop
         is to determine the employee's tax and output all salary
         data related to the employee.
        */
        grossSalary = baseSalary + bonus;
        
        if (grossSalary > 5000) {
            tax = (0.3 * (grossSalary - 5000)) + 600;
        }
        else if (grossSalary > 3000) {
            tax = (0.2 * (grossSalary - 3000)) + 200;
        }
        else if (grossSalary > 1000) {
            tax = (0.1 * (grossSalary - 1000));
        }
        else {
            tax = 0.00;
        }
        
        netSalary = grossSalary - tax;
        
        cout<<"Employeed #"<<numEmployee<<": "<<nameEmployee<<endl;
        cout<<"Base Salary: $"<<baseSalary<<endl;
        cout<<"Bonus: $"<<bonus<<endl;
        cout<<"Tax: $"<<tax<<endl;
        cout<<"Net Salary: $"<<netSalary<<endl;
        
        
        /*
         Loop continues until user inputs valid choice to input another employee
        */
        do {
            // Prompt user if they'd like to add another employee
            printf("Add another employee? (Y/N): "); cin >> userContinueChoice;
            
            // Set outtermost loop to end if user chose not to continue or clear buffer if invalid input
            if (toupper(userContinueChoice) == 'N') {
                shouldContinue = false;
            }
            else if (cin.fail() || ((toupper(userContinueChoice) != 'Y' && toupper(userContinueChoice) != 'N'))) {
                printf("Unknown choice encountered. Please enter a valid choice\n");
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
        } while (toupper(userContinueChoice) != 'Y' && toupper(userContinueChoice) != 'N');
        
        cin.ignore(1000, '\n');
    } while (shouldContinue);
    
    return 0;
}

