#include <bits/stdc++.h>
using namespace std ;
//virus
bool Divoc(vector<int> &v,int k){
    if(k==1) return v[0]==0 && v[1]==1 ;
    int m=1 << k-1 ;
    vector<int> v1(m) ;
    for(int i=0 ; i<m ; i++){ v1[i] =v[i] ;} //front

    vector<int> v2(v1) ;
    reverse(v2.begin(),v2.end()) ; //reverse front

    vector<int> v3(m) ;
    for(int i=0 ; i<m ; i++){ v3[i] =v[i+m] ;} //back
    
    bool A = Divoc(v1,k-1) ;
    bool B = Divoc(v2,k-1) ;
    bool C = Divoc(v3,k-1) ;

    return C && (A||B);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k ;
    cin >> n >> k ;
    int m = 1 << k ; 
    vector<int> v ;
    v.resize(m) ;
    while(n--){
        for(int i=0 ; i<m ; i++){
            cin >> v[i] ;
        }
        bool x = Divoc(v,k) ;
        if(x) cout << "yes\n" ;
        else cout << "no\n" ;
    }
}
