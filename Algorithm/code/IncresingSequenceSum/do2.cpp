#include <bits/stdc++.h>
using namespace std ;
int N;
int cnt=0;
void recur(int sum,int cur){
    if(sum==N){
        cnt++;
        return;
    }else if(sum<N){
        for(int i=cur;i<=N;i++){
            if(sum+i>N) break;
            recur(sum+i,i);
        }
    }
}
int main(){
    cin>>N ;
    recur(0,1);
    cout << cnt << endl;
}