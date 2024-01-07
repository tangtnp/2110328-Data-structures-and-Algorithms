#include <iostream>
#include <vector>

using namespace std;
int node,deg1,deg2;
vector<vector<int>> edge;
vector<bool> visited;
void dfs(int idx) {
  node++ ;
  visited[idx] = true ;
  if(edge[idx].size()==1) deg1++;
  if(edge[idx].size()==2) deg2++;
  for(auto e : edge[idx]){
    if(!visited[e])dfs(e) ;
  }

}

int main() {
  int v,e;
  cin>>v>>e;
  edge.resize(v);
  for (int i = 0;i < e;i++) {
    int a,b;
    cin>>a>>b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  visited.resize(v);
  int cc = 0;
  for (int i = 0;i < v;i++) {
    if (!visited[i]) {
      node = 0;
      deg1 =0;
      deg2 = 0 ;
      dfs(i);
      if(node==1 || deg1==2 && deg2==node-2){
        cc++;
      }
    }
  }
  cout << cc << endl;
}

