/* 
 * File:   Array.h
 * Author: Dr. Mark E. Lehr
 * Created on February 9, 2015, 8:43 AM
 *      Purpose:  Create an Array ADT
 */

#ifndef ARRAY_H
#define	ARRAY_H

class Array{
    private:
        int *data;
        int *indx;
        int size;
    public:
        void filAray(int);
        void prntAry(int);
        void destroy();
        void mrkSort();
};

void Array::mrkSort(){
    //Sort with the index
    for(int pos=0;pos<size-1;pos++){
        for(int lst=pos+1;lst<size;lst++){
            if(data[indx[pos]]>
               data[indx[lst]]){
                //Swap the indexes
                int temp=indx[pos];
                indx[pos]=indx[lst];
                indx[lst]=temp;
            }
        }
    }
}

void Array::destroy(){
    delete [] data;
    delete [] indx;
}

void Array::prntAry(int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void Array::filAray(int n){
    //Fill the array ADT
    if(n<=0)size=0;
    else size=n;
    //Now declare and allocate memory for the 
    //data
    data=new int[size];
    indx=new int[size];
    //Fill data with 2 digit numbers
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;
        indx[i]=i;
    }
}

#endif	/* ARRAY_H */

