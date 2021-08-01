#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int orig[30][30], after[30][30];
bool visited[30][30];
int n, m;

void input() {
    cin >> n >> m;
    for(int i= 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> orig[i][j];
        }
    }
    for(int i= 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> after[i][j];
        }
    }
}

bool bfs(int fx, int fy, int num) {
    int src = orig[fx][fy];
    queue<pii> q;
    orig[fx][fy] = num;
    visited[fx][fy] = true;
    q.push({fx, fy});
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || orig[nx][ny] != src) continue;
            orig[nx][ny] = num;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(orig[i][j] != after[i][j]) return false;
        }
    }
    return true;
}

int main() {
    fastio;
    input();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(orig[i][j] != after[i][j]) {
                bool ret = bfs(i, j, after[i][j]);
                if(ret) cout << "YES";
                else cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}