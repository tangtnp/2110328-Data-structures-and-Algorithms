#include <iostream>
#include <vector>

using namespace std;

int nodes, deg1, deg2;
vector<vector<int>> edge;
vector<bool> visited;

void dfs(int idx) {
  nodes++;
  visited[idx] = true;
  if (edge[idx].size() == 1) {
    deg1++;
  }
  if (edge[idx].size() == 2) {
    deg2++;
  }
  for (auto v : edge[idx]) {
    if (!visited[v]) {
      dfs(v);
    }
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
  int cc = 0;
  visited.resize(v);
  for (int i = 0;i < v;i++) {
    if (!visited[i]) {
      nodes = 0;
      deg1 = 0;
      deg2 = 0;
      dfs(i);
      if ((nodes == 1) || ((deg1 == 2) && (deg2 == nodes - 2))) {
        cc++;
        
      }
    }
  }
  cout<<cc<<endl;
}

//https://cedt-grader.nattee.net/submissions/1920727
