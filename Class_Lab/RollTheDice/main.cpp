/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 27, 2015, 8:45 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int rollDie(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    unsigned int nRolls=36000,nDie=2;
    int n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12;
    n2=n3=n4=n5=n6=n7=n8=n9=n10=n11=n12=0;
    //Take statistics on the random throws
    for(unsigned int roll=1;roll<=nRolls;roll++){
        int toss=rollDie(nDie);
        switch(toss){
            case 2:n2++;break;
            case 3:n3++;break;
            case 4:n4++;break;
            case 5:n5++;break;
            case 6:n6++;break;
            case 7:n7++;break;
            case 8:n8++;break;
            case 9:n9++;break;
            case 10:n10++;break;
            case 11:n11++;break;
            case 12:n12++;break;
            default:cout<<"Something went haywire!!!"<<endl;
        }
    }
    //As a check
    int tot=n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12;
    //Output the stats
    cout<<"2 was rolled "<<n2<<"(times)"<<endl;
    cout<<"3 was rolled "<<n3<<"(times)"<<endl;
    cout<<"4 was rolled "<<n4<<"(times)"<<endl;
    cout<<"5 was rolled "<<n5<<"(times)"<<endl;
    cout<<"6 was rolled "<<n6<<"(times)"<<endl;
    cout<<"7 was rolled "<<n7<<"(times)"<<endl;
    cout<<"8 was rolled "<<n8<<"(times)"<<endl;
    cout<<"9 was rolled "<<n9<<"(times)"<<endl;
    cout<<"10 was rolled "<<n10<<"(times)"<<endl;
    cout<<"11 was rolled "<<n11<<"(times)"<<endl;
    cout<<"12 was rolled "<<n12<<"(times)"<<endl;
    cout<<"Total rolls "<<tot<<"="<<nRolls<<endl;
    //Exit stage right
    return 0;
}

int rollDie(int nDice){
    //Declare variables
    int sum=0;
    for(int roll=1;roll<=nDice;roll++){
        sum+=(rand()%6+1);
    }
    return sum;
}
