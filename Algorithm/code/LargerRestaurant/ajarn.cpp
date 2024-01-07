#include <math.h> 
#include <map>
#include<vector>
#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll input, gap;
vector<ll> C;
map<ll, int> T;

int N, A;

pair<ll, ll> total_customers_at_time(ll time) {                 //      2 2 5     ->คำถาม     4 ,5 ,6, 8 
    ll cnt_h = 0;                                           //     T = {(2,2),(5,1)}
    ll cnt_l = 0;
    for (auto& i : T) {
        cnt_h += (time / i.first) * i.second;              //    (xxxxx / 2) * 2  + (xxxxx / 5) * 1
        cnt_l += ((time - 1) / i.first) * i.second;        //    (xxxx-1 / 2) * 2  + (xxxxx /5) *1  
    }
    return make_pair(cnt_l, cnt_h);
}

ll bin_search(ll time_begin, ll time_end, ll expected_val) { // 0, 9223372036854775807    ,  3 
    if (time_begin >= time_end) return time_begin;

    ll time_mid = (time_begin + time_end) / 2;

    pair<ll, ll> calculated_cus = total_customers_at_time(time_mid);

    if (expected_val >= calculated_cus.first && expected_val < calculated_cus.second) 
        return time_mid;

    else if (expected_val < calculated_cus.first) 
        return bin_search(time_begin, time_mid, expected_val);

    else return bin_search(time_mid, time_end, expected_val);
}

int main() {
    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        cin >> input;  // 2 2 5
        T[input]++;
    }
    
    for (int i = 0; i < A; i++) {
        cin >> input;                                   //4 
        cout << bin_search(0, -1, input - 1) << "\n";
    }

    return 0;
}
