#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  mSize += last-first;
  T *arr = new T[mSize]();
  size_t i=0 , j =0 ;
  for(;i<position-begin();i++){
    arr[i] = mData[i] ;
    j++ ;
  } //1 2

  for(auto itr = first; itr != last; itr++){
    arr[i] = *itr ;
    i++ ;
  }//1 2 10 20 30
  for(;i<mSize;i++){
    arr[i] = mData[j] ;
    j++;
  }
  delete [] mData;
  mData = arr;
  mCap = mSize;
}

#endif
