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
        x=m[m[t1]] ;
        y=m[m[t1]] ;
        
        if(x==y && t1!=t2 && 
        m.find(t1)!=m.end()&&m.find(t2)!=m.end() &&
        m.find(m[t1])!=m.end()&&m.find(m[t2])!=m.end()){cout << "YES"<<endl ;}
        else{cout << "NO" << endl ;}
        
    
}}