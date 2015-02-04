/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 4, 2015, 10:57 AM
 */

//System Libraries
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const int COL=30;

//Function Prototypes
void filAray(char [][COL],int,char);
void prntAry(char [][COL],int);
void inject(char [][COL],int,int,char);
void pause(int);
void gnrashn(char [][COL],int,char,char);
int  cntNbor(char [][COL],int,char,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare the 2 Dimensional character array
    const int ROW=7;
    char array[ROW][COL];
    int nGen=1;
    //Fill the array
    filAray(array,ROW,'*');
    //Print the array without the glider
    prntAry(array,ROW);
    //Inject the glider
    inject(array,2,13,'X');
    //Print the array with the glider
    prntAry(array,ROW);
    pause(1);
    //Game of life for generations stipulated
    for(int gen=1;gen<=nGen;gen++){
        gnrashn(array,ROW,'*','X');
        pause(5);
    }
    
    return 0;
}

void gnrashn(char a[][COL],int ROW,char d,char nd){
    for(int r=1;r<ROW-1;r++){
        cout<<" ";
        for(int c=1;c<COL-1;c++){
            int nBr=cntNbor(a,ROW,d,r,c);
            cout<<nBr;
            if(a[r][c]!=d&&nBr<=1)a[r][c]=d;
            if(a[r][c]!=d&&nBr>=4)a[r][c]=d;
            if(a[r][c]==d&&nBr==3)a[r][c]=nd;
        }
        cout<<endl;
    }
}

int  cntNbor(char a[][COL],int ROW,char d,int r,int c){
    //Count your neighbors
    int count=0;
    //3 on Top
    if(a[r-1][c-1]!= d)count++;
    if(a[r-1][c]  != d)count++;
    if(a[r-1][c+1]!= d)count++;
    //2 in Middle
    if(a[r][c-1]  != d)count++;
    if(a[r][c+1]  != d)count++;
    //3 on Bottom
    if(a[r+1][c-1]!= d)count++;
    if(a[r+1][c]  != d)count++;
    if(a[r+1][c+1]!= d)count++;
    //Return the count
    return count;
}

void pause(int secs){
    //Start the timer
    int strt=static_cast<unsigned int>(time(0));
    int end;
    do{
        end=static_cast<unsigned int>(time(0));
    }while(secs>(end-strt));
}

void inject(char a[][COL],int pRow,int pCol,char c){
    a[pRow+0][pCol+1]=c;
    a[pRow+1][pCol+2]=c;
    a[pRow+2][pCol+0]=c;
    a[pRow+2][pCol+1]=c;
    a[pRow+2][pCol+2]=c;
}

void prntAry(char a[][COL],int ROW){
    cout<<endl;
    for(int r=0;r<ROW;r++){
        for(int c=0;c<COL;c++){
            cout<<a[r][c];
        }
        cout<<endl;
    }
    cout<<endl;
}

void filAray(char a[][COL],int ROW,char d){
    for(int r=0;r<ROW;r++){
        for(int c=0;c<COL;c++){
            a[r][c]=d;
        }
    }
}

