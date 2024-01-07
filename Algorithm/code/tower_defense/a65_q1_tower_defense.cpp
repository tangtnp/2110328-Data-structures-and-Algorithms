#include <bits/stdc++.h>
using namespace std ;
int n ,m ,k ,w ;
int ans ;
vector<int> p ,h,t,hit;
vector<int> a ;
void b(int pos){
    if(pos==k){
    }
    int sum=0;
    for (int i = 0;i < m;i++) {
      sum += max(h[i] - hit[i],0);
    }
    if(sum<ans){
        ans =sum ;
    }else{
        for(int j=0;j<m;j++){
            a[pos] = j ;
            b(pos+1) ;
        }
    }
}
int main(){
    
    cin >> n >> m >> k >> w ;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        p.push_back(x) ;
    }

    for(int i=0;i<m;i++){
        int x;cin>>x;
        h.push_back(x) ;
    }
    for(int i=0;i<k;i++){
        int x;cin>>x;
        t.push_back(x) ;
    }
    sort(t.begin(),t.end());
    b(0);
    cout << ans <<endl ;

}