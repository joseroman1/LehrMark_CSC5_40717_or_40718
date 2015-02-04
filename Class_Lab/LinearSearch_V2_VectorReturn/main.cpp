/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 2nd, 2015, 9:16 AM
 *      Purpose:  Linear Search
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global constants

//Function prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
int  lSearch(int,const int [],int,int);//Linear Search
int  fndVals(int [],int,int,vector<int> &);//Fill Array with all value positions found
void prntFnd(const vector<int> &,int,int);//Print the found array
int  cntFnd(const int [],int,int);//Count the number of values found in the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and arrays
    const int ROW=1000;
    int pFilRow=100,perLine=10;
    int array[ROW]={};
    vector<int> found;
    //Fill the Arrays
    filAray(array,pFilRow);
    //Print the Arrays
    prntAry(array,pFilRow,perLine);
    //Find all the values
    int val=50;
    cout<<"Where is "<<val<<" found in the array!"<<endl;
    int nTimes=fndVals(array,pFilRow,val,found);
    //Print all the values found
    prntFnd(found,pFilRow,perLine);
    //How many times was the value found
    cout<<val<<" was found "<<nTimes<<"="
        <<cntFnd(array,pFilRow,val)<<" times"<<endl;
    //Exit stage right
    exit(0);
}

int fndVals(int a[],int n,int val,vector<int> &f){
    //Loop until you find all the elements
    //in the array
    int indx,pos=0;
    do{
        indx=lSearch(pos,a,n,val);
        f.push_back(indx);
        pos=indx+1;
    }while(indx>=0&&indx<n);
    return f.size()-1;
}

int  cntFnd(const int a[],int n,int val){
    //Loop until you find all the elements
    //in the array
    int indx,pos=0,count=0;
    do{
        indx=lSearch(pos,a,n,val);
        pos=indx+1;
        count++;
    }while(indx>=0&&indx<n);
    return --count;
}

int  lSearch(int posStrt,const int a[],int n,int val){
    //Loop until you find
    for(int indx=posStrt;indx<n;indx++){
        if(val==a[indx])return indx;
    }
    return -1;
}

//Print perLine Columns for the array output by row
void prntFnd(const vector<int> &a,int n,int perLine){
    cout<<endl;
    if(a.size()<=1){
        cout<<"The value was not found!"<<endl;
        cout<<endl;
        return;
    }
    cout<<"The value was found at these positions!"<<endl;
    for(int i=0;i<a.size()-1;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print perLine Columns for the array output by row
void prntAry(const int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Randomly fill the array with 2-digit numbers
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}