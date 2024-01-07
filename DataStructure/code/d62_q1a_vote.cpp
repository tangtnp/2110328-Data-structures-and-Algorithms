#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n , l ;
    cin >> n >> l;
    map<string,int> m;
    string name ;
    while(n--){
        cin >> name ;
        if(m.find(name) == m.end()){m[name]=0;}
        ++m[name] ;
    }
    priority_queue<int> pq ;
    int k = min(l,(int)m.size()) -1 ;
    for(auto e : m){
        pq.push(e.second) ;
    }
    while(k--){
        pq.pop() ;
    }
    cout << pq.top() << endl ;
}