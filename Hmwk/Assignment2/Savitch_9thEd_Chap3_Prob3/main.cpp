/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr *
 * Created on January 14, 2015, 11:20 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    bool cusp=false;
    int month,day;
    string sign;
    //Prompt for the input
    cout<<"Input the numerical/integer month you were born in"<<endl;
    cin>>month;
    cout<<"Input the integer day you were born on"<<endl;
    cin>>day;
    //Determine the sign
    if(month==1&&day<20)sign="Capricorn";
    else if(month==1&&day>=20)sign="Aquarius";
    else if(month==2&&day<=18)sign="Aquarius";
    //Output the sign and the cusp
    if(month==1&&day>18&&day<22)cusp=true;
    if(month==2&&day>16&&day<20)cusp=true;
    cout<<"Your sign is "<<sign;
    if(cusp)cout<<" and you are on the cusp"<<endl;
    else cout<<endl;
    return 0;
}

