#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int arr[5000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, idx = 0; cin >> n;
    for(int i = 0 ; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int m1, m2, m3;
    ll mSum = 3e9+1;
    for(int i = 0; i < n-2; ++i){
        int s = i + 1, e = n-1;
        while(s < e){
            ll sum = 1LL*arr[s] + arr[e] + arr[i];
            if(abs(sum) < mSum){
                m1 = arr[i]; m2 = arr[s]; m3 = arr[e];
                mSum = abs(sum);
            }
            if(sum <= 0) s++;
            else e--;
        }
    }
    cout << m1 << " " << m2 << " " << m3;
}