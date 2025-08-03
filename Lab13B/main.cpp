/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 07-10-2025
Instructor: Dr. Amar M. Maharjan
Description: Generates random array and outputs values
 along with minimum
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Struct to hold a 3D point and its distance from a reference point
struct Point {
    int x, y, z;
    double distance;
};

/*
Function:    readData
Parameters:  ifstream& inFile – input file stream for reading data
             Point points[] – array of Point structures
             int& size – reference to store number of points read
Return:      void
Description: Reads 3D point coordinates from input file and stores them in the array.
*/
void readData(ifstream& inFile, Point points[], int& size) {
    size = 0;
    while (inFile >> points[size].x >> points[size].y >> points[size].z) {
        size++;
    }
}

/*
Function:    findMin
Parameters:  Point points[] – array of Point structures
             Point userPoint – user-entered 3D point to compare against
             int size – number of elements in the array
Return:      Point – the point in the array closest to the user-entered point
Description: Returns the Point with the smallest distance.
*/
Point findMin(Point points[], Point userPoint, int size) {
    double minDist = -1;
    Point closestPoint;

    for (int i = 0; i < size; i++) {
        double dx = points[i].x - userPoint.x;
        double dy = points[i].y - userPoint.y;
        double dz = points[i].z - userPoint.z;
        points[i].distance = sqrt(dx * dx + dy * dy + dz * dz);

        if (minDist == -1 || points[i].distance < minDist) {
            minDist = points[i].distance;
            closestPoint = points[i];
        }
    }

    return closestPoint;
}

int main() {
    ifstream inFile("data.dat");
    // Check if file opened successfully
    if (!inFile) {
        cerr << "Error opening file data.dat" << endl;
        return 1;
    }

    Point points[20];
    int size;
    // Read data into array and close file
    readData(inFile, points, size);
    inFile.close();

    Point userPoint;
    cout << "Enter point: ";
    cin >> userPoint.x >> userPoint.y >> userPoint.z;

    // Find the closest point to user input
    Point closest = findMin(points, userPoint, size);

    // Display result
    cout << "The closet point is " << closest.x << " " << closest.y << " " << closest.z << endl;
    cout << "Minimum distance = " << closest.distance << endl;

    return 0;
}

