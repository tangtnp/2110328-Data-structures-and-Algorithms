#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <bits/stdc++.h>
//you can include any other file here
//you are allow to use any data structure

using namespace std ;
template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  vector<T> v ;
  set<T> stmp ;
  for(size_t i = 0 , j = 0; i<mSize ; ++i){
    if(stmp.find(mData[i])==stmp.end()){
      stmp.insert(mData[i]) ;
      v.push_back(mData[i]) ;
      mData[j] = v[j];
      j++ ;
    }
    
  } mSize = v.size() ;
}

#endif
