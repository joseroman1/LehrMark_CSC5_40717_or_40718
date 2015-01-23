/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 20, 2015, 6:45 PM
 *      Purpose:Using Random Numbers approximate pi
 * 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const float PI=4*atan(1);
const unsigned int MAXRAND=pow(2,31)-1;

//Function Prototype

//Execution begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //How many darts do you want to throw
    unsigned int nDarts,inCircl=0;
    //Prompt the user
    do{
        cout<<"This is a dart game"<<endl;
        cout<<"How many darts do you want to throw?"<<endl;
        cout<<"0 to 10^6"<<endl;
        cin>>nDarts;
    }while(nDarts>1000000);
    //Play the Game throw the darts
    for(int dart=1;dart<=nDarts;dart++){
        float x=1.0f*rand()/MAXRAND;//(0,1) x coordinate of the dart
        float y=1.0f*rand()/MAXRAND;//(0,1) y coordinate of the dart
        if(x*x+y*y<=1)inCircl++;
    }
    //Calculate the approximate value of pi
    float approxPi=4.0f*inCircl/nDarts;
    //Output the results
    cout<<"The exact value of pi = "<<PI<<endl;
    cout<<"The approximate value of pi = "<<approxPi<<endl;
    //Exit Stage Right!
    return 0;
}

