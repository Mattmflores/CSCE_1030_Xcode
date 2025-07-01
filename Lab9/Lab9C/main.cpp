/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-26-2025
Instructor: Dr. Amar M. Maharjan
Description: Excercise using functions
 based on result
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

// function declaration is provided
double compute_bonus(double base_salary, int experience);

int main()
{
    double base_salary;
    int experience;
    // get the values of base_salary
    printf("Enter base salary: "); scanf(" %lf", &base_salary);
    // and experience from the user
    printf("Enter experience: "); scanf(" %d", &experience);
    // call compute_bonus by passing necessary parameters
    const double bonus = compute_bonus(base_salary, experience);
    // display the bonus returned by the function
    printf("Bonus earned: %.2lf\n", bonus);
    return 0;
}

// function definition
/* Enter the function header here */
double compute_bonus(double base_salary, int experience)
{
    double bonus;
    // compare experience and calculate bonus
    bonus = experience > 10 ? 0.05 * base_salary : 0.03 * base_salary;
    // return the computed bonus
    return bonus;
}

