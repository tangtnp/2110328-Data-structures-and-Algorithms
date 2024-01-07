#include <bits/stdc++.h>
using namespace std ;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    vector<int> v,v2;
    map<int,int> num;
    cin >> n ;
    num[1] = 0;
    num[2] = 0;
    num[3] = 0 ;
    for(int i=0 ; i<n ; i++){
        cin >> m ;
        v.push_back(m) ;
        v2.push_back(m) ;
        num[m]++ ;
    }
    //cout << num[1] << " " << num[2] << " " << num[3] << endl;
    sort(v2.begin(),v2.end()) ;
    //
    vector<int> A1,A2,A3 ;
    for(int i=0;i<num[1];i++){
        A1.push_back(v[i]) ;
    }
    for(int i=num[1];i<num[1]+num[2];i++){
        A2.push_back(v[i]) ;
    }
    for(int i=num[1]+num[2];i<num[1]+num[2]+num[3];i++){
        A3.push_back(v[i]) ;
    }
    int A1_2 =0,A1_3=0,A2_1=0,A2_3=0,A3_1=0,A3_2=0;
    for(auto e : A1){if(e==2)A1_2++;if(e==3)A1_3++;}
    for(auto e : A2){if(e==1)A2_1++;if(e==3)A2_3++;}
    for(auto e : A3){if(e==1)A3_1++;if(e==2)A3_2++;}
    int cnt=0 ;
    int x,y,z ;

    x=min(A1_2,A2_1) ; A1_2-=x ;A2_1-=x;
    y=min(A1_3,A3_1) ; A1_3-=y ; A3_1-=y ;
    z=min(A2_3,A3_2) ; A2_3-=z ;A3_2-=z ;

    int p = ((A1_2 +A1_3+A2_1+A2_3+A3_1+A3_2)*2)/3 ;
    cout << x << " " << y << " " << z<< " " << p <<endl ;
    cnt = x+y+z+p ;
    cout << cnt ;
}