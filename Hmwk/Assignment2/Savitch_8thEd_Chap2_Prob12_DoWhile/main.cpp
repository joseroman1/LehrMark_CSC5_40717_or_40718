/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr *
 * Created on January 13, 2015, 10:15 AM
 * Purpose: Babylonian Square root calculator
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    float number,guess,r;
    int count=0;
    //Input a number
    cout<<"Input a number to estimate it's square root"<<endl;
    cout<<"The format fill be a positive float"<<endl;
    cin>>number;
    //First pass
    guess=number/2;
    do{
        r=number/guess;
        guess=(guess+r)/2;
        count++;
        //Output the first pass
        cout<<"Loop "<<count<<" calculate -> "<<guess<<endl;
    //}while(abs((r-guess)/r)>0.01);
    //}while(abs((number-r*r)/number)>0.01);
    }while((r-guess)!=0);
    //Exit stage right
    return 0;
}

