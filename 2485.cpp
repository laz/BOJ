#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    vector<int> gaps(n-1, 0);
    for(int i = 1; i < n; ++i){
        gaps[i-1] = v[i]-v[i-1];
    }

    int gap = 1e8;
    for(int i = 0; i < n-2; ++i){
        gap = min(gap, gcd(gaps[i], gaps[i+1]));
    }

    cout << (v[n-1]-v[0])/gap - (n-1) << endl;
}