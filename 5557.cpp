#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

ll cache[100][21];
int arr[100];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

ll d(int idx, int sum) {
    if(sum > 20 || sum < 0) return 0;
    
    if(idx == n-1) {
        if(sum == arr[n-1]) return 1;
        else return 0;
    }

    ll& ret = cache[idx][sum];
    if(ret != -1) return ret;

    return ret = d(idx+1, sum+arr[idx]) + d(idx+1, sum-arr[idx]);
}

int main() {
    input();

    memset(cache, -1, sizeof(cache));
    cout << d(1, arr[0]);
}