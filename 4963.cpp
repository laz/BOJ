#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool arr[52][52], visited[52][52];
int n, m;

void input() {
    cin >> m >> n;
    if(!n && !m) exit(0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
}

void bfs(int x, int y) {
    queue<pii> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        auto from = q.front(); q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = from.first + dx[i], ny = from.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || !arr[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    fastio;
    while(1) {
        input();
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(visited[i][j] || !arr[i][j]) continue;
                bfs(i, j);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}