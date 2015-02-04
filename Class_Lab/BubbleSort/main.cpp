/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 3, 2015, 10:10 AM
 *      Purpose:  Developing the bubble sort
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
void bblSort(int [],int);//With a swap function
void bublSrt(int [],int);//Without a swap function

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
    //Sort using Bubble Sort
    //bublSrt(array,pFilRow);//Without Swap function
    bblSort(array,pFilRow);//With Swap function
    //Print the sorted array
    prntAry(array,pFilRow,perLine);
    //Exit stage right
    exit(0);
}

void bublSrt(int a[],int n){
    //Declare a swap variable
    bool bSwap;
    //Do while swapping has occurred
    do{
        bSwap=false;
        //Swap as we go down the list
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                bSwap=true;
            }
        }
    }while(bSwap);
}

void bblSort(int a[],int n){
    //Declare a swap variable
    bool bSwap;
    //Do while swapping has occurred
    do{
        bSwap=false;
        //Swap as we go down the list
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                bSwap=true;
            }
        }
    }while(bSwap);
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