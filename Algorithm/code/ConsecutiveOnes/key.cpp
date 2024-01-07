#include <bits/stdc++.h>
using namespace std ;
int n,k ;
//COnsecutive ones
void solve(vector<bool>&v,int idx,int cnt,bool valid){
    if(idx < n){
        v[idx] = false ;
        solve(v,idx+1,0,valid) ;
        v[idx] = true ;
        solve(v,idx+1,cnt+1,valid||((cnt+1)>=k));
    }else if(valid){
        for(int i=0;i<n;i++)cout << v[i] ;
        cout << "\n" ;
    }
}
int main(){
    cin >> n >> k;
    vector<bool> sol(n) ;
    bool valid = false ;
    if(k==0) valid = true ;
    solve(sol,0,0,valid);
}
