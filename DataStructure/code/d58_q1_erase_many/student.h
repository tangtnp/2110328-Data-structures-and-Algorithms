#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  //mSize -= pos.size() ;
  size_t n = pos.size() ;
  T *arr = new T[mSize-n]();
  size_t i=0,j=0,k=0;
      for (;i < mSize;i++) {
        if(k>=n || i!=pos[k]){
          arr[j] = mData[i] ;
          j++;
          continue ;
        }
        k++ ;
      }
      delete [] mData;
      mData = arr;
      mSize = mSize-n ;
      mCap = mSize;
}

#endif
