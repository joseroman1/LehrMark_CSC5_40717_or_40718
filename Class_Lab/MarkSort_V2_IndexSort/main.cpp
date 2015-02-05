/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 3, 2015, 9:00 AM
 *      Purpose:  Developing a sorting routine
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global constants

//Function prototypes
void filAray(int [],int [],int);
void prntAry(const int [],const int [],int,int);
void prntAry(const int [],int,int);
void swap(int &,int &);//With xor's
void markSrt(const int [],int [],int);//Mark Sort in one function 

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and arrays
    const int ROW=100000;
    int pFilRow=100,perLine=10;
    int array[ROW]={};
    int index[ROW]={};
    //Fill the Arrays
    filAray(array,index,pFilRow);
    //Print the originals
    cout<<"Originals Before the Sort"<<endl;
    cout<<"Random Array"<<endl;
    prntAry(array,pFilRow,perLine);
    cout<<"Index"<<endl;
    prntAry(index,pFilRow,perLine);
    //Sort using Mark Sort
    markSrt(array,index,pFilRow);
    //Print the sorted array
    cout<<"The array using the sorted index"<<endl;
    prntAry(array,index,pFilRow,perLine);
    //Print the originals
    cout<<"Originals After the Sort"<<endl;
    cout<<"Random Array"<<endl;
    prntAry(array,pFilRow,perLine);
    cout<<"Index"<<endl;
    prntAry(index,pFilRow,perLine);
    //Exit stage right
    exit(0);
}

void markSrt(const int a[],int indx[],int n){
    //Apply swapMin from beginning to end
    for(int i=0;i<n-1;i++){
        //Swap elements at the top of the list
        //with the minimum
        for(int j=i+1;j<n;j++){
            //Swap individual elements with smaller
            if(a[indx[i]]>a[indx[j]])
                swap(indx[i],indx[j]);
        }
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
        cout<<setw(2)<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print perLine Columns for the array output by row
void prntAry(const int a[],const int indx[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Randomly fill the array with 2-digit numbers
void filAray(int a[],int indx[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
        indx[i]=i;
    }
}