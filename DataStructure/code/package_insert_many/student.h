#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::sort(data.begin(),data.end()) ;
  T *arr = new T[mSize+data.size()]();
  size_t k=0,j=0 ;
      for (auto &p : data) {
        for (;j-k < (size_t)p.first;j++){
          arr[j] = mData[j-k];
        }
        arr[j++] = p.second;
        ++k;
      }
      while(j-k<mSize){
        arr[j] = mData[j-k] ;
        ++j ;
      }


      delete [] mData;
      mData = arr;
      mSize += data.size() ;
      mCap = mSize;
}

#endif
