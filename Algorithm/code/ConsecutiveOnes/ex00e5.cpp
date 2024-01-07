#include <bits/stdc++.h>
using namespace std;
//เรียงเลขConsecutive-Leo
int n,k ;
vector<string> a ;
void mutate(int n,int idx,string str,int k){
    if(idx==n){
        int num1 = 0 ;
        int maxl = 0 ;
        for(char e : str){
            if(e=='1'){
                num1++;
                maxl = max(maxl,num1) ;
            }
            else if(e=='0') {
                num1=0;
            }
        }
        //cout << maxl << "\n" ;
        if(maxl < k) return ;
        cout << str << endl ;
        a.push_back(str) ;
        return;
    }
    mutate(n,idx+1,str+"0",k) ;
    mutate(n,idx+1,str+"1",k) ;
}

int main(){
    cin >> n >> k;
    mutate(n,0,"",k) ;
    return 0 ;
}