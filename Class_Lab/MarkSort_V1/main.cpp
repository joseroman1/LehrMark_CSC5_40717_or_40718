/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 3, 2015, 9:00 AM
 *      Purpose:  Developing a sorting routine
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global constants

//Function prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void swap(int &,int &);//With xor's
void swapMin(int,int [],int);//Swap as you go
void mrkSort(int [],int);//Mark Sort in 3 functions
void markSrt(int [],int);//Mark Sort in one function 

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and arrays
    const int ROW=100000;
    int pFilRow=100,perLine=10;
    int array[ROW]={};
    //Fill the Arrays
    filAray(array,pFilRow);
    //Print the Arrays
    prntAry(array,pFilRow,perLine);
    //Sort using Mark Sort
    markSrt(array,pFilRow);
    //Print the sorted array
    prntAry(array,pFilRow,perLine);
    //Exit stage right
    exit(0);
}

void markSrt(int a[],int n){
    //Apply swapMin from beginning to end
    for(int i=0;i<n-1;i++){
        //Swap elements at the top of the list
        //with the minimum
        for(int j=i+1;j<n;j++){
            //Swap individual elements with smaller
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void mrkSort(int a[],int n){
    //Apply swapMin from beginning to end
    for(int i=0;i<n-1;i++){
        swapMin(i,a,n);
    }
}

void swapMin(int pos,int a[],int n){
    //Swap as you go to place the minimum
    //element at the top of the list
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

void swap(int &a,int &b){
    //In place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
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