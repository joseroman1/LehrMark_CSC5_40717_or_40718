/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22, 2015, 7:30 PM
 *      Purpose:  Passes minimum muster
 */

//System Library
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float getData();
void calcScr(float,float,float,float,float);
float mn(float,float,float,float,float);
float mx(float,float,float,float,float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float d1,d2,d3,d4,d5;
    //Get the data
    d1=getData();
    d2=getData();
    d3=getData();
    d4=getData();
    d5=getData();
    //Calculate and output the score
    calcScr(d1,d2,d3,d4,d5);
    //Exit Stage Right!
    return 0;
}

void calcScr(float d1,float d2,float d3,
               float d4,float d5){
    float score=(d1+d2+d3+d4+d5
                 -mn(d1,d2,d3,d4,d5)
                 -mx(d1,d2,d3,d4,d5))/3;
    cout<<"The average is = "<<score<<endl;
}

float mx(float d1,float d2,float d3,
               float d4,float d5){
    //Find the minimum
    float max=d1;
    if(max<d2)max=d2;
    if(max<d3)max=d3;
    if(max<d4)max=d4;
    if(max<d5)max=d5;
    return max;
}

float mn(float d1,float d2,float d3,
               float d4,float d5){
    //Find the minimum
    float min=d1;
    if(min>d2)min=d2;
    if(min>d3)min=d3;
    if(min>d4)min=d4;
    if(min>d5)min=d5;
    return min;
}

float getData(){
    //Declare input/output variable
    float input;
    //Prompt and get data
    cout<<"What is Judge score!"<<endl;
    cin>>input;
    return input;
}