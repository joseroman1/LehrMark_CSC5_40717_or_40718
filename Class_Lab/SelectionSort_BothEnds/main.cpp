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
int  maxLst(int,int [],int);//Find maximum in the list
void mnmxLst(int,int [],int,int&,int&);//Find min max simultaneously
void slSortB(int [],int);//With a swap function and min/max functions
void selSrtB(int [],int);//Without functions
void slSrtBB(int [],int);//With swap and 1 minmax function
void slSrtBC(int [],int);//With swap and 1 counter
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
    //Sort using Selection Sort
    //selSrtB(array,pFilRow);
    //slSortB(array,pFilRow);
    //slSrtBB(array,pFilRow);
    slSrtBC(array,pFilRow);
    //Print the sorted array
    prntAry(array,pFilRow,perLine);
 /*   for(int i=0;i<pFilRow/2;i++){
        int indexB,indexE;
        mnmxLst(i,array,pFilRow-i,indexB,indexE);
        cout<<"Array min = "<<array[indexB]<<endl;
        cout<<"Array max = "<<array[indexE]<<endl;
        cout<<" i = "<<i<<endl;
        cout<<" indexE = "<<indexE<<endl;
        cout<<" indexB = "<<indexB<<endl;
        cout<<" pFilRow-1-i = "<<pFilRow-1-i<<endl;
        swap(array[i],array[indexB]);
        if(i==indexE)indexE=indexB;
        swap(array[indexE],array[pFilRow-1-i]);
        prntAry(array,pFilRow,perLine);
    }*/
    //Exit stage right
    exit(0);
}

void selSrtB(int a[],int n){
    //Swap as we go down the list
    for(int i=0,j=n-1;i<j;i++,j--){
        //Declare and set the minimum
        int min,indmn,indmx,max;
        indmn=indmx=i;
        min=max=a[i];
        //Loop and find the minimum in the list
        for(int k=i+1;k<j+1;k++){
            if(a[k]<min){
                min=a[k];
                indmn=k;
            }
            if(a[k]>max){
                max=a[k];
                indmx=k;
            }
        }
        if(i!=indmn){
            int temp=a[i];
            a[i]=a[indmn];
            a[indmn]=temp;
        }
        if(i==indmx)indmx=indmn;
        if(j!=indmx){
            int temp=a[j];
            a[j]=a[indmx];
            a[indmx]=temp;
        }
    }
}

void slSortB(int a[],int n){
    //Swap as we go down the list
    for(int i=0,j=n-1;i<j;i++,j--){
        int indx=minLst(i,a,j+1);
        if(i!=indx)swap(a[i],a[indx]);
        indx=maxLst(i,a,j+1);
        if(j!=indx)swap(a[j],a[indx]);
    }
}

void slSrtBB(int a[],int n){
    //Declare the indices
    int indxmn,indxmx;
    //Swap as we go down the list
    for(int i=0,j=n-1;i<j;i++,j--){
        mnmxLst(i,a,j+1,indxmn,indxmx);
        if(i!=indxmn)swap(a[i],a[indxmn]);
        if(i==indxmx)indxmx=indxmn;
        if(j!=indxmx)swap(a[j],a[indxmx]);
    }
}

void slSrtBC(int a[],int n){
    //With 2 functions and 1 counter
    for(int i=0;i<n/2;i++){
        int indexB,indexE;
        mnmxLst(i,a,n-i,indexB,indexE);
        swap(a[i],a[indexB]);
        if(i==indexE)indexE=indexB;
        swap(a[indexE],a[n-1-i]);
    }
}

void mnmxLst(int pos,int a[],int n,
        int &indxmn,int &indxmx){
    //Declare and set the minimum
    int min=a[pos],max=a[pos];
    indxmn=indxmx=pos;
    //Loop and find the minimum in the list
    for(int i=pos+1;i<n;i++){
        if(a[i]<min){
            min=a[i];
            indxmn=i;
        }
        if(a[i]>max){
            max=a[i];
            indxmx=i;
        }
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

int  maxLst(int pos,int a[],int n){
    //Declare and set the minimum
    int max=a[pos],indx=pos;
    //Loop and find the minimum in the list
    for(int i=pos+1;i<n;i++){
        if(a[i]>max){
            max=a[i];
            indx=i;
        }
    }
    return indx;
}

void swap(int &a,int &b){
    //In place swap using logical exclusive or's
    int temp=a;
    a=b;
    b=temp;
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