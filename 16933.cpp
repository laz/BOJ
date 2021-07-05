#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[1000][1000][11][2], arr[1000][1000];
int n, m, K;

struct state {
    int x, y, d, k; bool night;
    state(int xx, int yy, int dd, int kk, bool nn) {
        x = xx, y = yy, d = dd, k = kk, night = nn;
    }
};

void input() {
    cin >> n >> m >> K;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
}

int main() {
    fastio;
    input();

    queue<state> q;
    visited[0][0][0][0] = true;
    q.push(state(0, 0, 0, 0, false));   // day - false, night - true

    while(!q.empty()) {
        auto [x, y, d, k, night] = q.front(); q.pop();
        if(x == n-1 && y == m-1) {
            cout << d+1;
            return 0;
        }
        if(night) {
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny][k][!night] || arr[nx][ny]) continue;
                visited[nx][ny][k][!night] = true;
                q.push(state(nx, ny, d+1, k, !night));
            }
            if(visited[x][y][k][!night]) continue;
            visited[x][y][k][!night] = true;
            q.push(state(x, y, d+1, k, !night));
        }
        else {
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(k < K && !visited[nx][ny][k+1][!night]) {
                    visited[nx][ny][k+1][!night] = true;
                    q.push(state(nx, ny, d+1, k+1, !night));
                }
                if(visited[nx][ny][k][!night] || arr[nx][ny]) continue;
                visited[nx][ny][k][!night] = true;
                q.push(state(nx, ny, d+1, k, !night));
            }
        }
    }
    cout << -1;
}