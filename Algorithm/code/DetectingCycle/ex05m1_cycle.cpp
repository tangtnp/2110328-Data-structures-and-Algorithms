#include <bits/stdc++.h>
using namespace std ;
int main(){
    ios_base :: sync_with_stdio(false) ; 
    cin.tie(NULL) ;
    int T ; cin >> T ;
    while(T--){
        int N,E ;
        cin >> N >> E ;
        if(E==0) {cout << "NO" << "\n"; continue;}
        vector<vector<int>> G(N) ;
        vector<bool> visited(N,false) ;
        vector<int> from(N,-1) ;
        for(int i=0;i<E;i++){
            int a,b ; cin >> a >> b ;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        stack<int> s;
        bool check = false;
        int cnt = 0 ;
        while(cnt<N){
             for(int i =0;i<N;i++){
                if(visited[i]==false){
                    s.push(i);
                }
             }
             while(!s.empty()){
                int temp= s.top() ;
                s.pop();
                cnt++ ;
                if(!visited[temp]){
                    visited[temp]=true;
                    for(auto e : G[temp]){
                        if(!visited[e]){
                            from[e] = temp ;
                            s.push(e) ;
                        }else{
                            if(from[temp]!=e) check =true ;
                        }
                    }   
                }
            }
        }
    if(check) cout << "YES\n" ;
    else cout << "NO\n" ;
    
    }
    return 0 ;
}

#include <bits/stdc++.h>
using namespace std;
//detecting Cycle--pim
bool dfs(int n, int a, vector<vector<int>>& ed,
            vector<bool>& visited){
    visited[n] = true;
    for(int e : ed[n]){
        if(!visited[e]){
            if(dfs(e, n, ed, visited))
                return true;
        } else if(e != a){
            return true;
        }
    } 
    return false;    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, v, e, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v >> e;
        vector<vector<int>> ed(v);
        vector<bool> visited(v, false);
        for(int j = 0; j < e; j++){
            cin >> a >> b;
            ed[a].push_back(b);
            ed[b].push_back(a);
        } 
        bool ind = false;
        for(int j = 0; j < v; ++j){
            if(!visited[j]){
                if(dfs(j, -1, ed, visited)){
                    ind = true;
                    break;
                }
            }
        }
        cout << (ind ? "YES" : "NO") << "\n";
    }
}

