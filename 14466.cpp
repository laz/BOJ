#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool roads[101][101][101][101], visited[101][101];
vector<pii> cows;
int n, k, r;

void input() {
    cin >> n >> k >> r;
    for(int i = 0; i < r; ++i) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        roads[r1][c1][r2][c2] = true;
    }
    for(int i = 1; i <= k; ++i) {
        int a, b; cin >> a >> b;
        cows.push_back({a, b});
    }
}

// returns number of reachable cows 
void bfs(int x, int y) {
    queue<pii> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        auto [fx, fy] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = fx + dx[i], ny = fy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(visited[nx][ny] || roads[fx][fy][nx][ny] || roads[nx][ny][fx][fy]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    fastio;
    input();

    int cnt = 0;
    for(int i = 0; i < k; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(cows[i].first, cows[i].second);
        for(int j = i+1; j < k; ++j) {
            if(!visited[cows[j].first][cows[j].second]) cnt++;
        }
    }
    cout << cnt;
}