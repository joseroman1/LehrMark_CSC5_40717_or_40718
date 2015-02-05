/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 5, 2015, 10:00 AM
 *      Purpose:  Illustration Dynamic Memory
 *                with a sort
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *filAray(int);
void prntAry(int [],int,int);
int * markSrt(int *,int);
void swap(int [],int *);
void swap(int &,int &);
void destroy(int *);

int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize our array
    int size=100;
    int *array=filAray(size);
    //Print the array
    prntAry(array,size,10);
    //Sort the array
    int *barray=markSrt(array,size);
    //Print the results
    prntAry(barray,size,10);
    //Destroy the arrays
    destroy(array);
    destroy(barray);
    //Exit stage right!
    return 0;
}

int * markSrt(int *a,int n){
    //Allocate memory for a copy of the data
    if(n<=1)return 0;
    int *b=new int[n];
    //Copy the information
    for(int i=0;i<n;i++){
        *(b+i)=a[i];
    }
    //Sort the array
    for(int pos=0;pos<n-1;pos++){
        for(int lst=pos+1;lst<n;lst++){
            if(b[pos]>*(b+lst))swap(b[pos],*(b+lst));//swap(int &,int&)
            //if(*(b+pos)>b[lst])swap(&b[pos],(b+lst));//swap(int *,int*)
        }
    }
    //Return the result
    return b;
}

void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill a dynamic array with 2 digit random numbers
int *filAray(int n){
    //Allocate memory
    if(n<=1)return 0;
    int *a=new int[n];
    //Fill with random numbers
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    return a;
}

void destroy(int *a){
    delete []a;
}