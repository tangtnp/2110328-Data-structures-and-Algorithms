#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100001] ;
int visited[100001] ;
int ans = -1 ;
void dfs(int prev ,int idx,int cnt){
    visited[idx] = cnt ;
    for(auto e : edge[idx]){
        if(e != prev && ans ==-1){
            if(visited[e]==-1){
                dfs(idx,e,cnt+1) ;
            }else{
                ans = cnt-visited[e] +1 ;
                return ;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false) ;cin.tie(NULL) ;
    int V ; cin >> V ; 
    for(int i=0;i<V;i++){
        int a,b ;
        cin >> a >> b ;
        edge[a].push_back(b) ;
        edge[b].push_back(a) ;
        visited[i] = -1 ;
    }  
    dfs(-1,0,0) ;
    cout << ans <<"\n" ;
    
}