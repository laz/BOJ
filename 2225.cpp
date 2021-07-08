#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int MOD = 1e9;
int cache[202][202];    // 갯수 합
int n, k;

void input() {
    cin >> n >> k;
}

int d(int cnt, int sum) {
    
    if(cnt > k) return 0;
    if(sum == n) return 1;
    
    int& ret = cache[cnt][sum];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i = 0; i <= n; ++i) {
        if(sum+i > n) break;
        ret = (ret + d(cnt+1, sum+i)) % MOD;
    }
    return ret;
}

int main() {
    fastio;
    input();
    memset(cache, -1, sizeof(cache));
    cout << d(0, 0);
}