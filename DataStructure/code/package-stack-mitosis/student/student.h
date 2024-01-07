#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    if(mSize+b-a+1>mCap) expand(mCap*2) ;
    for(int i=0 ; i<a ; ++i){
        mData[mSize+b-a-i] = mData[mSize-i-1] ;
    }
    for(int i=0 ; i<=b-a;i++){
        mData[mSize+b-a -a-2*i] = mData[mSize-i-a-1] ;
        mData[mSize+b-a -a-2*i-1] = mData[mSize-i-a-1] ;
    }
    mSize += b-a+1 ;
    
}

#endif