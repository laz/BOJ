#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool visited[29][29];
double prob[4];
int n;

void input() {
    fastio;
    cout.precision(9);
    cin >> n;
    for(int i = 0; i < 4; ++i) {
        cin >> prob[i];
        prob[i] /= 100;
    }
}

double d(int x, int y, int cnt) {
    if(cnt == n) return 1;

    double ret = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(visited[nx][ny]) continue;
        visited[nx][ny] = true;
        ret += d(nx, ny, cnt+1) * prob[i];
        visited[nx][ny] = false;
    }
    return ret;
}

int main() {
    input();
    visited[n][n] = true;
    cout << d(n, n, 0);
}