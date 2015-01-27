/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 21, 2015, 10:31 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Function Prototypes
//FV = Future Value $'s
//PV = Present Value $'s
// i = Interest Rate per year
// n = Number of compounding periods in years
//FV         PV     i    n
float save1(float,float,int);
float save1(float,float,float=12.0f);//Defaulted Parameter for number of compounding periods
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);
float save4(float,float,float);//Overloaded function call, i.e. same name
void  save5(float &,float,float,float);//Reference Variable
int   save5(float &,float,float,int);//Static Variable

int main(int argc, char** argv) {
    //Declare and initialize values
    float prsVal=100.0f;//$100
    float intRate=6;//% Interest rate per year
    int   nCompnd=72/intRate;//By the of 72 to double
    float fCompnd=nCompnd;//Shows overloading from int to float
    float futrVal;//Reference variable passed into save5
    int   count;//Count how many times save5 is called
    //Convert interest to a fraction
    intRate/=100;
    //Output the inputs
    cout<<"Present Value = $"<<prsVal<<endl;
    cout<<"Interest Rate =  "<<intRate*100
            <<"%"<<endl;
    cout<<"Number of compounding Periods = "
            <<nCompnd<<"(years)"<<endl;
    //Output the Future value
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate,fCompnd)<<endl;
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate)<<endl;
    cout<<"Our Savings 2 = $"
            <<save2(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 3 = $"
            <<save3(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 4 = $"
            <<save4(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 4 = $"
            <<save4(prsVal,intRate,fCompnd)<<endl;
    save5(futrVal,prsVal,intRate,fCompnd);
    cout<<"Our Savings 5 = $"
            <<futrVal<<endl;
    for(int i=1;i<=5;i++){
        count=save5(futrVal,prsVal,intRate,nCompnd);
    }
    cout<<"Our Savings 5 using a static = $"
            <<futrVal<<endl;
    cout<<"The static variable/function was called "
            <<count<<" (times)"<<endl;
    //Exit Stage Right!
    return 0;
}

//Inputs
//p->Principal in $'s meaning present value
//i->Interest rate per year
//n->Number of compounding periods
//Output
//Savings->Future value in $'s
float save1(float p,float i,int n){
    return p*pow(1+i,n);
}

float save1(float p,float i,float n){
    return p*pow(1+i,n);
}

float save2(float p,float i,int n){
    return p*exp(n*log(1+i));
}

float save3(float p,float i,int n){
    for(int year=1;year<=n;year++){
        p*=(1+i);
    }
    return p;
}

float save4(float p,float i,int n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

float save4(float p,float i,float n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

void save5(float &s,float p,float i,float n){
    s=p*pow(1+i,n);
}

int save5(float &s,float p,float i,int n){
    static int nTimCld;
    s=p*pow(1+i,n);
    return ++nTimCld;
}