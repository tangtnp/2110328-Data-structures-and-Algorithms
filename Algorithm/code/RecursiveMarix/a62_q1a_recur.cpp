#include<bits/stdc++.h>
using namespace std ;
//recursive metrix
void recur(vector<vector<int>> &v, int a, int b,
        int top,int bottom,int left,int right){
    if(a<=0){
        v[top][left] = b;
        return ;
    }
    int s = 1 << (a-1) ;
    recur(v,a-1,b  ,top  ,top+s ,left  ,left+s) ;
    recur(v,a-1,b-1,top  ,top+s ,left+s,right) ;
    recur(v,a-1,b+1,top+s,bottom,left  ,left+s) ;
    recur(v,a-1,b  ,top+s,bottom,left+s,right) ;
}
int main(){
        int a,b ;
        cin >> a >> b ;
        int s =1<< a ;
        vector<vector<int>> v (s,vector<int>(s,0)) ;

        recur(v,a,b,0,s-1,0,s-1);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                cout << v[i][j] << " " ;
            }
            cout << endl;
        }
}