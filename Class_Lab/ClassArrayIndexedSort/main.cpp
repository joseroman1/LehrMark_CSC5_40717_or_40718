/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 9, 2015, 8:42 AM
 *      Purpose:  Test the Array ADT
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Array ADT
    int size=100,perLine=10;
    Array array;//Declared array object
    array.filAray(size);//Fill the array
    //Sort the array after filling
    array.mrkSort();
    //Print the Array ADT
    array.prntAry(perLine);
    //Clean up
    array.destroy();
    //Exit stage right!
    return 0;
}