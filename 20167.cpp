#include <iostream>
#include <algorithm>
using namespace std;

int arr[20];
int n, k;

int d(int idx, int sat){
    if(idx == n) return sat > k ? sat-k : 0;

    int ret = d(idx+1, sat);

    for(int i = idx; i < n; ++i){
        sat += arr[i];
        if(sat >= k){
            ret = max(ret, d(i+1, 0) + (sat - k));
            break;
        }
    }

    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    cout << d(0, 0);
}