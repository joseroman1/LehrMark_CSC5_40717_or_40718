/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 15, 2015, 7:51 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    int input;
    int sum=0,sumPos=0,sumNeg=0,sumEven=0,sumOdd=0;
    //Prompt for an input and sum
    for(int count=1;count<=10;count++){
        cout<<"Enter an integer!"<<endl;
        cin>>input;
        sum+=input;
        if(input>0)sumPos+=input;
        else sumNeg+=input;
        if(input%2)sumOdd+=input;
        else sumEven+=input;
    }
    //Output the result
    cout<<"The Sum =          "<<setw(4)<<sum<<endl;
    cout<<"The Positive Sum = "<<setw(4)<<sumPos<<endl;
    cout<<"The Negative Sum = "<<setw(4)<<sumNeg<<endl;
    cout<<"The Even Sum =     "<<setw(4)<<sumEven<<endl;
    cout<<"The Odd Sum =      "<<setw(4)<<sumOdd<<endl;
    //Exit Stage right!
    return 0;
}

