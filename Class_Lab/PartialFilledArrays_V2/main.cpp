/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 29, 2015, 9:16 AM
 *      Purpose:  Utilizing partially filled arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global constants
const int COL=200;

//Function prototypes
void filAray(int [],int);
void filAray(vector<int> &,int);
void filAray1to2(int [],int,int);
void filAray(int [][COL],int,int);
void prntAry(const int [],int,int);
void prntAry(const vector<int> &,int,int);
void prntAry1to2(const int [],int,int);
void prntAry(const int [][COL],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and arrays
    const int ROW=200;
    int pFilCol=10,pFilRow=10,perLine=5;
    int array[COL];
    vector<int> varray(COL);
    int array1to2[ROW*COL];
    int array2D[ROW][COL];
    //Fill the Arrays
    filAray(array,pFilCol);
    filAray(varray,pFilCol);
    filAray1to2(array1to2,pFilRow,pFilCol);
    filAray(array2D,pFilRow,pFilCol);
    //Print the Arrays
    prntAry(array,pFilCol,perLine);
    prntAry(varray,pFilCol,perLine);
    prntAry1to2(array1to2,pFilRow,pFilCol);
    prntAry(array2D,pFilRow,pFilCol);
    //Exit stage right
    exit(0);
}

//Print perLine Columns for the array output by row
void prntAry(const vector<int> &a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
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

//Print a 1 Dimensional array as if it were 2 Dimensions
void prntAry1to2(const int a[],int r,int c){
    cout<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i*COL+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Print a 2 Dimensional array
void prntAry(const int a[][COL],int r,int c){
    cout<<endl;
    for(int row=0;row<r;row++){
        for(int col=0;col<c;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Randomly fill a 1 Dimensional array as if it were 2 Dimensions
void filAray1to2(int a[],int r,int c){
    //Where i is the row index and j is the column index
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i*COL+j]=rand()%90+10;
        }
    }
}

//Randomly fill a 2 Dimensional array
void filAray(int a[][COL],int r,int c){
    for(int row=0;row<r;row++){
        for(int col=0;col<c;col++){
            a[row][col]=rand()%90+10;
        }
    }
}

//Randomly fill a vector with 2-digit numbers
void filAray(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

//Randomly fill the array with 2-digit numbers
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}