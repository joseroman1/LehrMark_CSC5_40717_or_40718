/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on January 8, 2015, 8:15 PM
* Purpose: Homework assignment 1
*/
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and Initialize variables
    float gasTank=20;//Max gallons in our gas tank
    float inTown=21.5;//In town miles per gallon
    float onHway=26.8;//Highway miles per gallon
    //Calculate the total miles in and out of town
    float disTown=gasTank*inTown;
    float disHway=gasTank*onHway;
    //Output the results
    cout<<"Distance in Town on a tank of gas      = ";
    cout<<disTown<<"(miles)"<<endl;
    cout<<"Distance on Highway with a tank of gas = ";
    cout<<disHway<<"(miles)"<<endl;
    return 0;
}

