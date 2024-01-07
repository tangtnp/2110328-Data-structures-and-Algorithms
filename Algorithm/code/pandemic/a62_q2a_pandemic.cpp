#include<bits/stdc++.h>
using namespace std;

bool outofbounds(int a, int b){
    return a < b && a >= 0;
}
//pandemic
void solve(vector<vector<int>>& geo, int d,
int r, int c, int& ct){
    if(d == 0) return;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(geo[i][j] == 3+d){
                if(outofbounds(i-1,r)) {
                    if(geo[i-1][j] == 0){
                    geo[i-1][j] = 2+d; ct++;
                    }
                }
                if(outofbounds(i+1,r)) {
                    if(geo[i+1][j] == 0){
                    geo[i+1][j] = 2+d; ct++;
                    }
                }
                if(outofbounds(j-1,c)) {
                    if(geo[i][j-1] == 0){
                    geo[i][j-1] = 2+d; ct++;
                    }
                }
                if(outofbounds(j+1,c)) {
                    if(geo[i][j+1] == 0){
                    geo[i][j+1] = 2+d; ct++;
                    }
                }
            }
        }
    }
    solve(geo,d-1,r,c,ct);
}

int main(){
    //pandemic
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> arr(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    int ct = 0;
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            if(arr[i][j] == 1){
                ct++;
                if(outofbounds(i-1,r)) {
                    if(arr[i-1][j] == 0){
                    arr[i-1][j] = 2+t;
                    ct++;
                    }
                }
                if(outofbounds(i+1,r)) {
                    if(arr[i+1][j] == 0){
                    arr[i+1][j] = 2+t;
                    ct++;
                    }
                }
                if(outofbounds(j-1,c)) {
                    if(arr[i][j-1] == 0){
                    arr[i][j-1] = 2+t; ct++;
                    }
                }
                if(outofbounds(j+1,c)) {
                    if(arr[i][j+1] == 0){
                    arr[i][j+1] = 2+t; ct++;
                    }
                }
            }
        }
    }
    solve(arr,t-1,r,c,ct);
    cout << ct;
}
