/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-21-2025
 Instructor: Dr. Amar M. Maharjan
Description:
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
    int numEmployee = 1;
    int hoursWorked;
    double baseSalary, netSalary;
    double bonus = 100.00, tax;
    int userJobChoice;
    char userContinueChoice;
    bool shouldContinue = true;
    string nameEmployee;
    bool validName = true, nameIsEmpty = true, validHours, validJob;
    
    srand(static_cast<unsigned int>(time(0)));
    
    do {
        printf("Calculating Salary for Employee #%d\n", numEmployee);
        
        ++numEmployee;
        
        do {
            printf("Enter emplyee name (alphabets and spaces only): "); getline(cin, nameEmployee);
            
            for (int i = 0; i < nameEmployee.length(); ++i) {
                const char whitespace = 32; // ASCII value for space
                const bool nameContainsInvalidChar = !isalpha(nameEmployee.at(i)) && nameEmployee.at(i) != whitespace;
                const bool shouldCapitalize = (i == 0 && isalpha(nameEmployee.at(i))) || (i != 0 && nameEmployee.at(i - 1) == whitespace && isalpha(nameEmployee.at(i)));
                
                if (nameContainsInvalidChar) {
                    validName = false;
                    printf("Invalid name! Use alphabets and spaces only.\n");
                    break;
                }
                
                if (shouldCapitalize) {
                    nameEmployee[i] = toupper(nameEmployee.at(i));
                    nameIsEmpty = false;
                }
            }
            
            if (nameIsEmpty) printf("Invalid name! Use alphabets and spaces only.\n");
            
        } while (!validName || nameIsEmpty);
        
        do {
            printf("Enter hours worked this month: "); cin >> hoursWorked;
            if (cin.fail() || hoursWorked < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                printf("Invalid hours input! Restarting entry\n");
                validHours = false;
            }
            else {
                validHours = true;
                cin.ignore(1000, '\n');
            }
        } while (!validHours);
        
        do {
            printf("Select job role: \n1. Manager \n2. Developer \n3. Tester \n4. Intern \n");
            printf("Enter role number: "); cin >> userJobChoice;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
            validJob = true;
            switch (userJobChoice) {
                case MANAGER:
                    baseSalary = 5000.00;
                    break;
                case DEVELOPER:
                    baseSalary = 4000.00;
                    break;
                case TESTER:
                    baseSalary = 3000.00;
                    break;
                case INTERN:
                    baseSalary = 1500.00;
                    break;
                default:
                    validJob = false;
                    printf("Unknown role encountered. Please enter a valid role\n");
                    break;
            }
        } while (!validJob);
        
        do {
            printf("Add another employee? (Y/N): "); cin >> userContinueChoice;
            
            if (toupper(userContinueChoice) == 'N') {
                shouldContinue = false;
            }
            else if (cin.fail() || ((toupper(userContinueChoice) != 'Y' && toupper(userContinueChoice) != 'N'))) {
                printf("Unknown choice encountered. Please enter a valid choice\n");
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
        } while (toupper(userContinueChoice) != 'Y' && toupper(userContinueChoice) != 'N');
        
    } while (shouldContinue);
    
    return 0;
}

