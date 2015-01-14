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
const int CNVHRMN=60;//Conversion from Hrs to Mins
const int CNVMNSC=60;//Conversion from Min to Secs


//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Assignment 2 Menu Prompt
    cout<<"Solution 1 Savitch 8thEd Chap 2 Prob 2"<<endl;
    cout<<"Solution 2 Savitch 9thEd Chap 2 Prob 3"<<endl;
    cout<<"You get the idea"<<endl;
    cout<<"Input which solution you would like to see"<<endl;
    int choice;
    cin>>choice;
    //Based upon the choice, display the results
    switch(choice){
        case 1:{
            cout<<"You have choosen Solution 1"<<endl;
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
            break;
        }
        case 2:{
            cout<<"You have chosen Solution 2"<<endl;
            //Declare variables
            float mph;//Miles per hour on a treadmill
            float hpm;//Pace as hours per mile
            float fmpm;//Miles per minute as a float
            int   impm;//Miles per minute as an integer
            float fmspm;//Fraction left for seconds per mile
            //Prompt for the input
            cout<<"How many miles are you running"<<endl;
            cout<<"in an hour?"<<endl;
            cout<<"Format answer as a float."<<endl;
            cin>>mph;
            //Calculate the relevant pace
            hpm=1/mph;
            fmpm=hpm*CNVHRMN;
            impm=static_cast<int>(fmpm);
            fmspm=(fmpm-impm)*CNVMNSC;
            //Output the result
            cout<<mph<<" (mph) = ";
            cout<<impm<<" (mins) ";
            cout<<fmspm<<" (secs) per mile"<<endl;
            break;
        }
        default: cout<<"Incorrect Choice!"<<endl;
    }
    //Exit Stage Right!
    return 0;
}

