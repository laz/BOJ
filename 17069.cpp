#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

bool arr[32][32];
ll cache[32][32][3];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

// 0 right
// 1 down
// 2 diag
bool done(int x, int y, int type) {
    if(type == 0 && x == n-1 && y == n-2) return true;
    else if(type == 1 && x == n-2 && y == n-1) return true;
    else if(type == 2 && x == n-2 && y == n-2) return true;
    return false;
}

// 0 right
// 1 down
// 2 diag
bool able(int x, int y, int move) {
    if(move == 0 && y+1 < n && !arr[x][y+1]) return true;
    else if(move == 1 && x+1 < n && !arr[x+1][y]) return true;
    else if(move == 2 && x+1 < n && y+1 < n && !arr[x+1][y] && !arr[x][y+1] && !arr[x+1][y+1]) return true;
    return false;
}

ll d(int x, int y, int type) {
    if(done(x, y, type)) return 1;

    ll& ret = cache[x][y][type];
    if(ret != -1) return ret;

    ret = 0;
    if(type == 0) {
        if(able(x, y+1, 0)) ret += d(x, y+1, 0);
        if(able(x, y+1, 2)) ret += d(x, y+1, 2);
    }
    else if(type == 1) {
        if(able(x+1, y, 1)) ret += d(x+1, y, 1);
        if(able(x+1, y, 2)) ret += d(x+1, y, 2);
    }
    else {
        if(able(x+1, y+1, 0)) ret += d(x+1, y+1, 0);
        if(able(x+1, y+1, 1)) ret += d(x+1, y+1, 1);
        if(able(x+1, y+1, 2)) ret += d(x+1, y+1, 2);
    }

    return ret;
}

int main() {
    input();

    memset(cache, -1, sizeof(cache));
    cout << d(0, 0, 0);
}