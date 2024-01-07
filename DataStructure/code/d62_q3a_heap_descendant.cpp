#include <bits/stdc++.h>
using namespace std ;
int main(){
     int n, a;
    cin >> n >> a;

    vector<int> ans;

    ans.push_back(a);

    for(int i=0;i<ans.size();i++){
        int c = ans[i];
        int left = c*2+1;
        int right = c*2+2;
        if(left<n) ans.push_back(left);
        else break;
        if(right<n) ans.push_back(right);
        else break;
    }
    cout << ans.size() << "\n";
    for(auto x : ans)cout << x << " ";
}