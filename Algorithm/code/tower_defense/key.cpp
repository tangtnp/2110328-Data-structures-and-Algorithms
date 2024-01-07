#include <iostream>
#include <vector>


using namespace std;

vector<int> t,h,p; 
vector<int> a; // a[i] = index of a monter aimed by i-th tower
int w;
int n,m,k;
int ans;

void brute(int step) {
  if (step == k) {
    vector<int> hit(m);
    for (int i = 0;i < k;i++) {
      int tower_pos = t[i];
      int monster_idx = a[i];
      if (abs(p[monster_idx] - tower_pos) <= w) {
        hit[monster_idx]++;
        hit[monster_idx] = std::min(h[monster_idx],hit[monster_idx]);
      }
    }

    //sum hit
    int sum = 0;
    for (int i = 0;i < m;i++) {
      sum += max(h[i] - hit[i],0);
    }
    if (sum < ans) {
      ans = sum;
    }

  } else {
    for (int j = 0;j < m;j++) {
      a[step] = j;
      brute(step+1);
    }
  }
}

int main() {
  cin >> n >> m >> k >> w;

  p.resize(m);
  h.resize(m);
  t.resize(k);
  ans = 0;
  for (int i = 0;i < m;i++) { cin >> p[i]; }
  for (int i = 0;i < m;i++) { cin >> h[i]; ans += h[i];}
  for (int i = 0;i < k;i++) { cin >> t[i]; }

  a.resize(k);
  brute(0);
  cout << ans << endl;
}