#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
//Columbia
const int INF = 100000000;

typedef pair<int, pair<int, int>> PII;

vector<vector<int>> map, shortest;
set<PII> q;

bool inbound(int r, int c) {
  return not (r < 0 or c < 0 or r >= map.size() or c >= map[0].size());
}

int dir[4][2] = {
  {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

void dijkstra() {
  shortest[0][0] = 0;
  q.insert(make_pair(0, make_pair(0,0)));

  while (not q.empty()) {
    PII now = *q.begin();
    q.erase(q.begin());

    int r = now.second.first, c = now.second.second;
    
    int tohere = shortest[r][c];
    if (now.first > tohere) continue;
    for (int i = 0; i < 4; ++i) {
      int rr = r + dir[i][0];
      int cc = c + dir[i][1];
      if (not inbound(rr, cc)) continue;
      int candidate = tohere + map[rr][cc];
      if (not (candidate < shortest[rr][cc])) continue;
      
      q.erase(PII(shortest[rr][cc], make_pair(rr,cc)));
      shortest[rr][cc] = candidate;
      q.insert(PII(candidate, make_pair(rr,cc)));
    }
  }
}

int main() {
  int R, C;
  cin >> R >> C;
  map.resize(R);
  shortest.resize(R);
  for (int i = 0; i < R; ++i) {
    map[i].resize(C);
    shortest[i].resize(C);
    for (int j = 0; j < C; ++j) {
      cin>>map[i][j];
      shortest[i][j] = INF;
    }
  }
  dijkstra();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout<<shortest[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}

//https://cedt-grader.nattee.net/submissions/1924075