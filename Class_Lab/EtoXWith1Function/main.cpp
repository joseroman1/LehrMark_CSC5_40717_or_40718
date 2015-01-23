/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 21, 2015, 8:55 AM
 *      Purpose:Factorial
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype
int nFactrl(int);//Note:  nFactrl with an elll
int nFactr1(int);//Note:  nFactr1 with a one

//Execution begins here!
int main(int argc, char** argv) {
    //Declare variables
    float x,approxEx=1;
    //Prompt the user for the power of e^x
    cout<<"What x in e^x would you like to use?"<<endl;
    cin>>x;
    //Calculate the approximate e^x
    for(int n=1;n<=13;n++){
        //approxEx+=(pow(x,n)/nFactrl(n));
        approxEx+=(pow(x,n)/nFactr1(n));
    }
    //Compare the results
    cout<<"Approximate e^x = "<<approxEx<<endl;
    cout<<"Exact e^x       = "<<exp(x)<<endl;
    //Exit Stage right
    return 0;
}

int nFactrl(int n){
    //Declare the variable
    //Note: function only works for values 0 to 13
    int factorial=1;
    if(n==0||n==1)return factorial;
    else if(n<=13){
        for(int i=2;i<=n;i++){
            factorial*=i;
        }
        return factorial;
    }else{
        return -1;
    }
}

int nFactr1(int n){
    //Declare the variable
    //Note: function only works for values 0 to 13
    int factorial=1;
    if(n==0||n==1)factorial=1;
    else if(n<=13){
        for(int i=2;i<=n;i++){
            factorial*=i;
        }
    }else{
        factorial=-1;
    }
    return factorial;
}
