#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    T a = mData[(mFront+pos)%mCap] ;
  for(int i=0;i<pos;i++){
    mData[(mFront+pos-i+mCap)%mCap]= mData[(mFront+pos-i-1+mCap)%mCap];
  }
  mData[(mFront)%mCap] = a ;
}

#endif
