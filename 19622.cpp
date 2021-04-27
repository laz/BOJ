#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[100000], cache[100000];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b >> arr[i];
    }
}

int d(int idx) {
    if(idx >= n-2) {
        return arr[idx];
    }
    
    int& ret = cache[idx];
    if(ret != -1) return ret;

    return ret = max(d(idx+2) + arr[idx], d(idx+3) + arr[idx]);
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));
    cout << max(d(0), d(1));
}