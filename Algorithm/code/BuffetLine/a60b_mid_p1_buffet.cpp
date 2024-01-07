#include <bits/stdc++.h>
using namespace std ;
int main(){
    int f,w,n ;
    cin >> f >> w >> n ;
    vector<int> arr(n+1,false) ;
    for(int i=0;i<f;i++){
        int xf; 
        cin >> xf ;
        arr[xf] = true ;
    }
    int cnt=0;
    for(int i=1 ; i<=n;){
        if(arr[i]){
            cnt++ ;
            for(int j=i ; j<=i+2*w && j<=n;j++){
                arr[j] = false ;
            }
            i+=2*w;
        }
        i++;
    }
    cout << cnt ;
}
//https://cedt-grader.nattee.net/submissions/1923939