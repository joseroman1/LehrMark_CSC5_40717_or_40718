/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 27, 2015, 8:45 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int rollDie(int);
void outStat(int [],int [],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    unsigned int nGames=1000000,nDie=2;
    int nThrows=0,maxThrow=0;
    const int SIZE=13;
    int win[SIZE]={},loss[SIZE]={};
    //Play the game
    for(unsigned int game=1;game<=nGames;game++){
        //Throw the dice
        int sum1=rollDie(nDie),gThrow=0;
        nThrows++;gThrow++;
        //Win-Loss or keep rolling
        if(sum1==7||sum1==11)win[sum1]++;
        else if(sum1==2||sum1==3||sum1==12)loss[sum1]++;
        else{
            //Keep rollin until you stop
            bool stop=false;
            do{
                //Roll the die 
                int sumN=rollDie(nDie);
                nThrows++;gThrow++;
                //Check for win or loss
                if(sumN==7){
                    loss[sum1]++;
                    stop=true;
                }else if(sumN==sum1){
                    win[sum1]++;
                    stop=true;
                }
            }while(!stop);
        }
        if(gThrow>maxThrow)maxThrow=gThrow;
    }
    //Output
    cout<<"Games played = "<<nGames<<endl;
    cout<<"Averaqe Throws/Game = "<<1.0f*nThrows/nGames<<endl;
    cout<<"During one of the games a set of dice was thrown "
        <<maxThrow<<"(times)"<<endl;
    outStat(win,loss,nGames,SIZE);
    //Exit stage right
    return 0;
}

void outStat(int win[],int loss[],int nGames,int SIZE){
    //Declare Variables
    int totWin=0,totLoss=0,totGame;
    for(int i=0;i<SIZE;i++){
        totWin+=win[i];
        totLoss+=loss[i];
    }
    totGame=totWin+totLoss;
    //Output the total Stats
    cout<<"Total Games Played "<<totGame<<" = "<<nGames<<endl;
    cout<<"Total Wins   = "<<totWin<<endl;
    cout<<"Total Lost   = "<<totLoss<<endl;
    cout<<"Percent Win  = "<<100.0f*totWin/totGame<<"%"<<endl;
    cout<<"Percent Loss = "<<100.0f*totLoss/totGame<<"%"<<endl;
    //Output the individual Stats compared to total
    cout<<"Wins and Losses compared to total"<<endl;
    cout<<"Die   Win%   Loss%"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    for(int i=2;i<SIZE;i++){
        cout<<setw(2)<<i
            <<setw(8)<<100.0f*win[i]/totGame
            <<setw(8)<<100.0f*loss[i]/totGame<<endl;
    }
    cout<<"Wins and Losses compared to Die thrown"<<endl;
    cout<<"Die   Win%   Loss%"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    for(int i=2;i<SIZE;i++){
        cout<<setw(2)<<i
            <<setw(8)<<100.0f*win[i]/(win[i]+loss[i])
            <<setw(8)<<100.0f*loss[i]/(win[i]+loss[i])<<endl;
    }
}

int rollDie(int nDice){
    //Declare variables
    int sum=0;
    for(int roll=1;roll<=nDice;roll++){
        sum+=(rand()%6+1);
    }
    return sum;
}