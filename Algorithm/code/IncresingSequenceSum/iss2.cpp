#include<iostream>
#include<vector>
using namespace std ;
int n , cnt=0 ;
void check(int sum , const int &k){
    if(sum==n) {cnt++ ; return ;}
    if(sum<n){
        for(int i=k;k<=n;i++){
            if(sum+i>n) break ;
            check(sum+i,i) ;
        }
    }
}
int main(){
    cin >> n ;
    int s = 0 ;
    check(s,1) ;
    cout << cnt ;

}