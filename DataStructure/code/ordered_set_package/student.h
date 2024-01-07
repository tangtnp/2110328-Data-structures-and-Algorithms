#include <vector>
using namespace std;
#include<algorithm>
template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v(A);
    for(const auto &u : B){
        if(find(v.begin(),v.end(),u)==v.end()){
            v.push_back(u) ;
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    for(const auto  &u : A){
        if(find(B.begin(),B.end(),u)!=B.end()){
            v.push_back(u) ;
        }
    }
    return v;
}
