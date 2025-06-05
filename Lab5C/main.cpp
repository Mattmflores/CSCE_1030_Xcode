/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-05-2025
Instructor: Dr. Amar M. Maharjan
Description: Displays seasonal message based on user input
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    // Declare variables
    enum Season {WINTER = 'W', SPRING = 'G', SUMMER = 'S', FALL = 'F'};
    char userChoice;
    
    // Prompt user for choice of season
    printf("Enter season:S for summer, F for fall, W for winter and G for spring:");
    scanf(" %c", &userChoice);
    
    // Output message based on choice of season
    switch (userChoice) {
        case FALL:
            printf("The weather looks good.\n");
            break;
        case SPRING:
            printf("The flowers are blooming.\n");
            break;
        case SUMMER:
            printf("It is rather hot outside.\n");
            break;
        case WINTER:
            printf("It is rather cold outside.\n");
            break;
        default:
            printf("Wrong choice.\n");
            break;
    }
    
    return 0;
}
