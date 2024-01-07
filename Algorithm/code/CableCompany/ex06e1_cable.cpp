#include <bits/stdc++.h>
using namespace std ;
vector<int> G ;
int findSet(int idx){
    if(G[idx]==-1) return idx;
    G[idx] = findSet(G[idx]) ;
    return G[idx] ;
}
void Union(int x,int y){
    int s1=findSet(x);
    int s2=findSet(y) ;
    G[s1]=s2 ;  
}
int main(){
    int N ; cin >> N ;
    int start = 1 ;
    G.resize(N) ;
    for(int i=0;i<G.size();i++){
        G[i] = -1;
    }
    vector<pair<int,pair<int,int>>> v;
    for(int i =0;i<N-1;i++){
        for(int j =i+1;j<N;j++){
            int a; cin >> a;
            v.push_back(make_pair(a,make_pair(i,j))) ;
        }
    }
    sort(v.begin(),v.end()) ;
    vector<int> x ;
    for(auto itr = v.begin();itr!=v.end();itr++){
        if(findSet((*itr).second.first)!=findSet((*itr).second.second)){
            Union(findSet((*itr).second.first),findSet((*itr).second.second)) ;
            x.push_back((*itr).first) ;
        }
    }
    int c=0;
    for(auto e:x) c+=e;
    cout << c;
    return 0;
}

//prim
//https://cedt-grader.nattee.net/submissions/1922631
//kruskul
//https://cedt-grader.nattee.net/submissions/1922643
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//kruskal
int n,x,ans;
vector<int> p, s;
struct edge {
    int u;
    int v;
    int w;
};
vector<edge> e;
bool cmp(edge x, edge y) {
    return x.w < y.w;
}
int findSet(int u) {
    if (u != p[u]) {
        p[u] = findSet(p[u]);
    }
    return p[u];
}
void unionSet(int u, int v) {
    if (s[u] < s[v]) {
      p[u] = v;
      s[v] += s[u];
    } else {
      p[v] = u;
      s[u] += s[v];
    }
    
}
int main() {
    cin>>n;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n-1; i++) {
      p[i] = i;
      s[i] = 1;
      for (int j = i+1; j < n; j++) {
            cin>>x;
            edge temp;
            temp.u = i;
            temp.v = j;
            temp.w = x;
            e.push_back(temp);
        }
    }
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0, t = 0; t < n-1; i++) {
        int a = e.at(i).u;
        int b = e.at(i).v;
        if (findSet(a) != findSet(b)) {
            t++;
            ans += e.at(i).w;
            unionSet(findSet(a), findSet(b));
        }
    }
    cout<<ans<<endl;
}

