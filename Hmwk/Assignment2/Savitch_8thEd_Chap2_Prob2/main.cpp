/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr *
 * Created on January 14, 2015, 10:35 AM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float CNVLBGM=453.6;//Grams per pound

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    const float CONC=1e-3f;//Sweetener concentration
    float wtCoke=3.5e2f;//Weight of coke in grams
    float kMouse=5.0f;//Quantity of sweetener that kills a mouse in grams
    float wtMouse=3.5e1f;//Wt of mouse in grams
    float kPer, wtDsPer;
    int   nCans;
    //Input the desire wt of person
    cout<<"Input your desired weight in lbs"<<endl;
    cout<<"Format the input as a float"<<endl;
    cin>>wtDsPer;
    wtDsPer*=CNVLBGM;//Convert to grams
    //Calculation
    kPer=kMouse/wtMouse*wtDsPer;
    nCans=kPer/wtCoke/CONC;
    //Output the limit of what you can drink
    cout<<"Number of cans of diet coke ";
    cout<<"that will kill you = "<<nCans<<endl;
    //Exit Stage Right!
    return 0;
}

