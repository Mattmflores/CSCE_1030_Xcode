/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-05-2025
Instructor: Dr. Amar M. Maharjan
Description: Computes bonus based on number of sales and years of experience
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    // Declare variables
    double numSales, bonus = 100.00; // minimum bonus is 100 irrespective of sales
    int numExperience;
    
    // Prompt for number of sales and years of experience
    printf("Enter sales: "); scanf(" %lf", &numSales);
    printf("Enter experience: "); scanf(" %d", &numExperience);
    
    // Add percent of sales to bonus based on years of experience
    bonus = numExperience >= 10 ? bonus += 0.03 * numSales : bonus += 0.02 * numSales;
    
    // Add additional bonus if threshold met
    if (numSales > 100000.00) bonus += 500;
    
    // Display bonus to two decimal points
    printf("Computed bonus: $%.2lf \n", bonus);
    
    return 0;
}
