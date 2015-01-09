/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on January 8, 2015, 6:28 PM
* Purpose: Homework assignment (Savitch_9thEd_Chap1_ProgProj1)
*/
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int op1,op2,sum=0,prod=1;
    //Prompt for the two operands
    cout<<"Input 2 integers having a range of [-2^31,2^31-1]"<<endl;
    cin>>op1>>op2;
    //Calculate the sum and the product
    sum=sum+op1;
    sum=sum+op2;
    prod=prod*op1;
    prod=prod*op2;
    //Output the results
    cout<<op1<<" + "<<op2<<" = "<<sum<<endl;
    cout<<op1<<" * "<<op2<<" = "<<prod<<endl;
    //Exit stage right!
    return 0;
}

