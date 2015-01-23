/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22, 2015, 7:30 PM
 *      Purpose:  Possibly what the book asked
 *                for but professor will give
 *                me an FFFF for doing
 *                      Global Variables
 *                      Disgusting Function Names
 *                      Using integer on Min/Max Function
 */

//System Library
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
float d1,d2,d3,d4,d5;

//Function Prototypes
void getJudgeData();
void calcScore();
float minimum();
float maximum();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Get the data
    getJudgeData();
    //Calculate and output the score
    calcScore();
    //Exit Stage Right!
    return 0;
}

void calcScore(){
    float score=(d1+d2+d3+d4+d5
                 -minimum()-maximum())/3;
    cout<<"The average is = "<<score<<endl;
}

float maximum(){
    //Find the minimum
    float max=d1;
    if(max<d2)max=d2;
    if(max<d3)max=d3;
    if(max<d4)max=d4;
    if(max<d5)max=d5;
    return max;
}

float minimum(){
    //Find the minimum
    float min=d1;
    if(min>d2)min=d2;
    if(min>d3)min=d3;
    if(min>d4)min=d4;
    if(min>d5)min=d5;
    return min;
}

void getJudgeData(){
    //Prompt and get data
    cout<<"What is Judge #1's score!"<<endl;
    cin>>d1;
    cout<<"What is Judge #2's score!"<<endl;
    cin>>d2;
    cout<<"What is Judge #3's score!"<<endl;
    cin>>d3;
    cout<<"What is Judge #4's score!"<<endl;
    cin>>d4;
    cout<<"What is Judge #5's score!"<<endl;
    cin>>d5;
}