#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int cache[201][201];
int arr[200];
int n, k;

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

// l~r 구간을 통일시키는 최소 횟수
int d(int l, int r) {
    
    int& ret = cache[l][r];
    if(ret != -1) return ret;

    if(l == r) return ret = 0;

    ret = 2e9;
    for(int i = l; i < r; ++i) {
        int cur = d(l, i) + d(i+1, r);
        if(arr[i+1] != arr[l]) cur++;
        ret = min(ret, cur);
    }
    return ret;
}

int main() {
    fastio;
    input();
    memset(cache, -1, sizeof(cache));
    cout << d(0, n-1);
}