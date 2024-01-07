#include<iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool sortA(double* i,double* j) {return i[2] < j[2];}
int main(){
    double w;
    int n;
    cin >> w >> n;
    double temp[n][3];
    for(int i=0;i<n;i++) cin >> temp[i][0];
    for(int i=0;i<n;i++) cin >> temp[i][1];
    vector<double*> a;
    for(int i=0;i<n;i++){
        temp[i][2] =  temp[i][0]/temp[i][1];
        a.push_back(temp[i]);
    }
    double total = 0;
    sort(a.begin(),a.end(),sortA);
    while(w>0 && a.size()>0){
        if(a.back()[1]<=w){
            total += a.back()[0];
            w -= a.back()[1];
            a.pop_back();
        }
        else {
            total += w*a.back()[2];
            break;
        }
    }
    cout << fixed << setprecision(4) << total;
}

//https://cedt-grader.nattee.net/submissions/1922938