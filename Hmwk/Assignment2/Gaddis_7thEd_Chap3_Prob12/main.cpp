/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr *
 * Created on January 14, 2015, 11:20 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    string month,year;
    float totCash,sales,dolSTax,dolCTax;
    float sSlsTax=4e-2f,cSlsTax=2e-2f;
    //Prompt for inputs
    cout<<"What month of sales to calculate?"<<endl;
    getline(cin,month);
    cout<<"What year of sales to calculate?"<<endl;
    getline(cin,year);
    cout<<"What was the total Cash received?"<<endl;
    cin>>totCash;
    //Calculations required
    sales=totCash/(1+sSlsTax+cSlsTax);
    dolSTax=sales*sSlsTax;
    dolCTax=sales*cSlsTax;
    //Output Everything
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Month: "<<month<<" Year: "<<year<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Total Collected:       $ "<<setw(8)<<totCash<<endl;
    cout<<"Sales:                 $ "<<setw(8)<<sales<<endl;
    cout<<"County Sales Tax:      $ "<<setw(8)<<dolCTax<<endl;
    cout<<"State Sales Tax:       $ "<<setw(8)<<dolSTax<<endl;
    cout<<"Total Sales Tax:       $ "<<setw(8)<<dolCTax+dolSTax<<endl;
    //Exit Stage Right!
    return 0;
}

