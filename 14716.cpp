#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int arr[252][252];
bool visited[252][252];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
}

void bfs(int x, int y) {
    queue<pii> q;
    visited[x][y] = 1;
    q.push({x, y});
    while(!q.empty()) {
        auto [fx, fy] = q.front(); q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = fx + dx[i], ny = fy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 0  || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    fastio;
    input();

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(arr[i][j] && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}