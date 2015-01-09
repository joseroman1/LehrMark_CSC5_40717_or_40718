/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on January 8, 2015, 7:18 PM
* Purpose: Homework assignment 1
*/
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONVPCT=100;//Percent Conversion

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float skPrice=2.177e1f;//Stock Price in $'s
    unsigned short nShares=600;//Number of shares of stock
    char comish=2;//2 percent sales commission
    //Calculate sales price, commission and total in $'s
    float slPrice=nShares*skPrice;
    float cmPrice=slPrice*comish/CONVPCT;
    float totPaid=slPrice+cmPrice;
    //Output the results
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Sales Price = $"<<setw(8)<<slPrice<<endl;
    cout<<"Commission  = $"<<setw(8)<<cmPrice<<endl;
    cout<<"Total Paid  = $"<<setw(8)<<totPaid<<endl;
    //Exit stage right!
    return 0;
}

