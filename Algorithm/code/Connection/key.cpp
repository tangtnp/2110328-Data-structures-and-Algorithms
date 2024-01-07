#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//connection
vector<vector<int>> edge;
vector<bool> visited;
vector<int> dis;
int bfs(int idx, int k) {
  queue<int> q;
  q.push(idx);
  dis[idx] = 0;
  visited[idx] = true;
  int num = 0;
  while (!q.empty()) {
    num++;
    int x = q.front();
    int d = dis[x];
    q.pop();
    if (d >= k) {
      continue;
    }
    for (auto y:edge[x]) {
      if (!visited[y]) {
        visited[y] = 1;
        dis[y] = d + 1;
        q.push(y);
      }
    }
  }
  return num;
}

int main() {
  int v,e,k;
  cin>>v>>e>>k;
  edge.resize(v);
  for (int i = 0;i < e;i++) {
    int a,b;
    cin>>a>>b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  visited.resize(v);
  dis.resize(v);
  int maxNum = 0;
  for (int i = 0; i < v;i++) {
    for (int j = 0; j < v; j++) {
      visited[j] = false;
      dis[j] = 1000000000;
    }
    int num = bfs(i, k);
    if (num > maxNum) {
      maxNum = num;
    }
  }
  cout<<maxNum<<endl;
}
//https://cedt-grader.nattee.net/submissions/1921279
//use bfs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, k;

int bfs(vector<int> gp[], int now, vector<bool>& visited){
    queue<int> q;
    vector<int> dis(n, n);
    q.push(now);
    visited[now] = true;
    dis[now] = 0;
    int cnt = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(dis[top] == k)
            continue;
        for(auto x: gp[top]){
            if(!visited[x]){
                visited[x] = true;
                cnt++;
                q.push(x);
                dis[x] = dis[top]+1;
            }
        }
    }
    return cnt;
}

int main(){
    int a, b;
    cin >> n >> e >> k;
    vector<int> gp[n];
    for(int i=0; i<e; i++){
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        vector<bool> visited(n, false);
        int cnt = bfs(gp, i, visited);
        mx = max(mx, cnt);
    } 
    cout << mx;
}
