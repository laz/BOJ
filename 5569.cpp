#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int MOD = 100000;

int cache[100][100][2][2];     // 0 up 1 right  // unable able
int w, h;

void input() {
    fastio;
    cin >> w >> h;
}

int main() {
    input();

    for(int i = 1; i < h; ++i) cache[i][0][0][1] = 1;
    for(int i = 1; i < w; ++i) cache[0][i][1][1] = 1;

    for(int i = 1; i < h; ++i) {
        for(int j = 1; j < w; ++j) {
            cache[i][j][0][0] = cache[i-1][j][1][1];
            cache[i][j][0][1] = (cache[i-1][j][0][0] + cache[i-1][j][0][1]) % MOD;
            cache[i][j][1][0] = cache[i][j-1][0][1];
            cache[i][j][1][1] = (cache[i][j-1][1][0] + cache[i][j-1][1][1]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            ans = (ans + cache[h-1][w-1][i][j]) % MOD;
        }
    }
    cout << ans;
}