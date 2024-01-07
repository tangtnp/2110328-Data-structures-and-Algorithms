#include <bits/stdc++.h>
using namespace std ;
int main(){
    //3ValueSort-Win
    ios_base::sync_with_stdio(false);cin.tie(NULL) ;
    int n,cnt=0,c=0;
    cin >> n;
    vector<int> v(n),s;
    for(auto &e : v) cin >> e ;
    s = v ;
    sort(s.begin(),s.end());
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]==s[j] && v[j]==s[i]
            && s[i]!=v[i] && s[j]!=v[j] ){
                swap(v[i],v[j]) ;
                cnt++ ;
                break ;
            }
        }  
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=s[i]) c++ ;
    }
    cout << cnt +(c*2)/3 << endl ;
    return 0 ;

}