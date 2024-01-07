#include <bits/stdc++.h>
using namespace std ;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n , c ;
    cin >> n >> c ;
    map<long long,long long> m ;
    long long f ,s ;
    while(n--){
        cin >> f >> s ;
        m[s] = f ;
    }
    long long t1,t2 ;
    long long x,y;
    while(c--){
        cin >> t1 >> t2 ;
        if(m[m[t1]]==m[m[t2]]&&m[m[t1]]!=0&&m[m[t2]]!=0&&t1!=t2){
            cout << "YES" << endl ;
        }else cout << "NO" <<endl ;
}}