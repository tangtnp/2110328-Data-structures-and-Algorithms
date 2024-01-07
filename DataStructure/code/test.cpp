#include<bits/stdc++.h>
using namespace std ;
void print_range1(int step,int goal) {
if (step < goal) {
std::cout << step << " ";
print_range1(step+1, goal);
}
}

void print_range2(int step,int goal) {
if (step < goal) {
print_range2(step+1, goal);
std::cout << step << " ";
}
}

int main(){
    print_range1(0,5) ;
    cout << endl << "%%%%%%\n" ;
    print_range2(2,5) ;
}