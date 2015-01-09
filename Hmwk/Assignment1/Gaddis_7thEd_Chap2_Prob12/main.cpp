/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on January 8, 2015, 7:45 PM
* Purpose: Homework assignment 1
*/
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const unsigned short CVFTACS=43560;//Percent Conversion

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    float inSqFt,outAcrs;
    //Prompt for input
    cout<<"Input the number of square feet"<<endl;
    cout<<"to convert to Acres"<<endl;
    cin>>inSqFt;
    //Calculate Acres
    outAcrs=inSqFt/CVFTACS;
    //Output the results
    cout<<inSqFt<<"(sq feet) = ";
    cout<<outAcrs<<"(acres)"<<endl;
    //Exit stage right!
    return 0;
}

