/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 29, 2015, 9:16 AM
 *      Purpose:  Utilizing partially filled arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global constants

//Function prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
int  lSearch(int,const int [],int,int);
int  bSearch(int &,const int [],int &,int);
int  fndVals(int [],int,int,int[]);
void prntFnd(const int [],int,int);
int  cntFnd(const int [],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables and arrays
    const int ROW=1000;
    int pFilRow=100,perLine=10;
    int array[ROW]={};
    int found[ROW]={};
    //Fill the Arrays
    filAray(array,pFilRow);
    //Print the Arrays
    prntAry(array,pFilRow,perLine);
    //Find all the values
    int val=0;
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

int fndVals(int a[],int n,int val,int f[]){
    //Loop until you find all the elements
    //in the array
    int indx,pos=0,count=0;
    bSearch(pos,a,n,val);
    do{
        indx=lSearch(pos,a,n,val);
        f[count++]=indx;
        pos=indx+1;
    }while(indx>=0&&indx<n);
    //if(f[count-1]!=-1)f[count]=-1;
    return --count;
}

int  cntFnd(const int a[],int n,int val){
    //Loop until you find all the elements
    //in the array
    int indx,pos=0,count=0;
    bSearch(pos,a,n,val);
    do{
        indx=lSearch(pos,a,n,val);
        pos=indx+1;
        count++;
    }while(indx>=0&&indx<n);
    return --count;
}

int  bSearch(int &strt,const int a[],int &end,int val){
    int middle;
    do{
        middle=(end+strt)/2;
        if(a[middle]==val)return middle;
        else if(a[middle]>val){
            end=middle-1;
        }else{
            strt=middle+1;
        }
    }while(strt<=end);
    return -1;
}

int  lSearch(int posStrt,const int a[],int n,int val){
    //Loop until you find
    for(int indx=posStrt;indx<n;indx++){
        if(val==a[indx])return indx;
    }
    return -1;
}

//Print perLine Columns for the array output by row
void prntFnd(const int a[],int n,int perLine){
    cout<<endl;
    if(a[0]==-1){
        cout<<"The value was not found!"<<endl;
        cout<<endl;
        return;
    }
    cout<<"The value was found at these positions!"<<endl;
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            cout<<endl;
            return;
        }
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

//Fill an array sequentially which makes it sorted
//but with lots of similar values
void filAray(int a[],int n){
    //for 3 of the same of values
    int div=10;
    for(int i=0;i<n;i++){
        a[i]=i/div;
    }
}