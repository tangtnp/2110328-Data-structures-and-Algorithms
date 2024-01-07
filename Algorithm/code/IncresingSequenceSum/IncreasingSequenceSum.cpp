#include <bits/stdc++.h>
using namespace std ;
int cnt=0;
//incresing sum sequence earth
//5 -- <1,1,1,2>
int n ;
void check (int sum ,const int &rec){
    if(sum==n){cnt++ ; return;}
    if(sum<n){
        for(int i=rec;i<=n;i++){
            if(sum+i>n)break ;
            check(sum+i,i) ;
        }
    }
    
}

int main(){
    
    cin >> n ;
    int s=0 ;
    check(s,1) ; 
    cout << cnt ;
    return 0 ;
}