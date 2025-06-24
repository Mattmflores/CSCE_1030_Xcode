/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-24-2025
Instructor: Dr. Amar M. Maharjan
Description: Outputs int values above average based on user inputs
*/

#include <iostream>
using namespace std;

int main()
{
    const int SIZE=12; //12 students
    int SIZE_ABOVE_AVERAGE=0;//elements of height larger than above_average
    int sum_height=0; //variable for sum of heights
    int height[SIZE]; //array to store height of 12 students
    int above_average[SIZE]; //store all above average heights in this array
    double average; //variable for average of heights
    
    for(int i=0;i<SIZE;++i)
    {
        cout<<"Enter height in inches of students #"<<i+1<<":";
        cin>>height[i]; //read heights, one student at a time
        //compute sum of heights
        sum_height += height[i];
    }
    //compute average of heights
    average = static_cast<double>(sum_height) / SIZE;
    //in a loop check if heights is above average
    //copy to above_average array if it is
    for(int i=0;i<SIZE;++i)
    {
        if (height[i] > average)
        {
            above_average[SIZE_ABOVE_AVERAGE] = height[i];
            ++SIZE_ABOVE_AVERAGE;
        }
    }
    
    cout<<"You entered:"<<endl;
    for(int i=0;i<SIZE;++i)
    {
        //display the heights entered by the user
        cout<<"Height in inches of student #"<<i+1<<":"<<height[i]<<endl;
    }
    
    //display the average height
    cout<<"Average:"<<average<<endl;
    cout<<"Above average:"<<endl;
    //display all heights above average in a loop
    for(int i=0;i<SIZE_ABOVE_AVERAGE;++i)
    {
        cout<<above_average[i]<<endl;
    }
    
    return 0;
}
