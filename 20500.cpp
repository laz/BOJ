#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define MOD 1000000007
using namespace std;

int cache[1516][3];
int n;

void input() {
    fastio;
    cin >> n;
    cache[2][0] = 1;    // 1 2  
    cache[2][1] = 1;    // 2 0  
    cache[2][2] = 0;    // 0 1  
}

int main() {
    input();

    for(int i = 3; i <= n; ++i) {
        cache[i][0] = (cache[i-1][1] + cache[i-1][2]) % MOD;
        cache[i][1] = (cache[i-1][0] + cache[i-1][2]) % MOD;
        cache[i][2] = (cache[i-1][1] + cache[i-1][0]) % MOD;
    }

    cout << cache[n][0];
}