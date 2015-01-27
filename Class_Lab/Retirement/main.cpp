/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 27, 2015, 9:10 AM
 *      Purpose:  Use the Babylonian 10
 *           for retirement.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
//For overloaded functions return type does not matter
//only the types associated with parameters in the argument list
//Pass by reference vs. pass by value does not count
//when overloading the function name
float retirement(float,float,float,int);
void  retirement(float &,float,float,float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    float salary=150000.0f;
    float invRate=0.05f;//http://california.municipalbonds.com/bonds/recent
    float defPrct=0.20f;//Babylonian 10
    float ndSave=salary/invRate;
    float retSav=0;
    float nmYears;
    //Heading
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"You need to save $"<<ndSave<<endl;
    cout<<"Year     Savings"<<endl;
    //Calculate When We can Retire
    for(int year=1;retSav<=ndSave;year++){
    //for(int year=1;year<=60;year++){
        //retSav=retirement(0.0,invRate,defPrct*salary,year);
        retSav=0;
        retirement(retSav,invRate,defPrct*salary,year*1.0f);
        cout<<setw(4)<<year<<setw(12)<<retSav<<endl;
    }
    //Exit stage right!
    return 0;
}

void retirement(float &p,float i,float d ,float n){
    for(int year=1;year<=n;year++){
        p*=(1+i);
        p+=d;
    }
}

float retirement(float p,float i,float d,int n){
    for(int year=1;year<=n;year++){
        p*=(1+i);
        p+=d;
    }
    return p;
}