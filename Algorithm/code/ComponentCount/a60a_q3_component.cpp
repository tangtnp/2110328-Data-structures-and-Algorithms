#include <bits/stdc++.h>
using namespace std ;
int v , e ;
vector<vector<int>> edge ;
vector<bool> visited ;
void dfs(int idx){
     visited[idx] = true ;
     for(auto e : edge[idx]){
        if(!visited[e])
            dfs(e) ;
     }
} 
int main(){
    cin >> v >> e ;
    edge.resize(v) ;
    for(int i=0; i<e;i++){
        int a,b ;
        cin >> a >> b ;
        a--;b--;
        edge[a].push_back(b) ;
        edge[b].push_back(a) ;
    }
    visited.resize(v) ;
    int cc=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            cc++ ;
            dfs(i) ;
        }
    }
    cout << cc << endl ;
    
    
}