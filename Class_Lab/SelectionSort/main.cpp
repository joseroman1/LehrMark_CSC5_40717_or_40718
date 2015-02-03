/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 3, 2015, 10:10 AM
 *      Purpose:  Developing the selection sort
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
int  minLst(int,int [],int);//Find minimum in the list
void selSort(int [],int);//With a swap function
void selcSrt(int [],int);//Without functions

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and arrays
    const int ROW=100000;
    int pFilRow=100000,perLine=10;
    int array[ROW]={};
    //Fill the Arrays
    filAray(array,pFilRow);
    //Print the Arrays
    prntAry(array,pFilRow,perLine);
    //Sort using Selection Sort
    selcSrt(array,pFilRow);
    //Print the sorted array
    prntAry(array,pFilRow,perLine);
    //Exit stage right
    exit(0);
}

void selcSrt(int a[],int n){
    //Swap as we go down the list
    for(int i=0;i<n-1;i++){
        //Declare and set the minimum
        int min=a[i],indx=i;
        //Loop and find the minimum in the list
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                indx=j;
            }
        }
        if(i!=indx){
            int temp=a[i];
            a[i]=a[indx];
            a[indx]=temp;
        }
    }
}

void selSort(int a[],int n){
    //Swap as we go down the list
    for(int i=0;i<n-1;i++){
        int indx=minLst(i,a,n);
        if(i!=indx)swap(a[i],a[indx]);
    }
}

int  minLst(int pos,int a[],int n){
    //Declare and set the minimum
    int min=a[pos],indx=pos;
    //Loop and find the minimum in the list
    for(int i=pos+1;i<n;i++){
        if(a[i]<min){
            min=a[i];
            indx=i;
        }
    }
    return indx;
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