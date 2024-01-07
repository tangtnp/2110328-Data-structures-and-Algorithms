#include <bits/stdc++.h>
using namespace std;int f,w,n,a,s,t;
//buffet
int main(){
    cin>>f>>w>>n;
    set<int>food;
    for(int i=0;i<f;i++) 
        cin>>a,food.insert(a);
    for(auto a:food){
        if(a>t) t=a+2*w,s++;
    }cout<<s;
    }
