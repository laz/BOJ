#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct state{
    int x, y, d, cnt;
    state(int xx, int yy, int dd, int cc) {
        x = xx, y = yy, d = dd, cnt = cc;
    }
};

int dx[12] = {1, 0, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[12] = {0, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};

bool arr[200][200], visited[200][200][31];
int n, m, k;

void input() {
    fastio;
    cin >> k >> m >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    input();
    queue<state> q;
    visited[0][0][0] = true;
    q.push(state(0, 0, 0, 0));
    while(!q.empty()) {
        auto from = q.front(); q.pop();
        if(from.x == n-1 && from.y == m-1) {
            cout << from.d;
            return 0;
        }
        for(int i = 0; i < 4; ++i) {
            int nx = from.x + dx[i], ny = from.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny][from.cnt] || arr[nx][ny]) continue;
            visited[nx][ny][from.cnt] = true;
            q.push(state(nx, ny, from.d+1, from.cnt));
        }
        if(from.cnt < k) {
            for(int i = 4; i < 12; ++i) {
                int nx = from.x + dx[i], ny = from.y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny][from.cnt+1] || arr[nx][ny]) continue;
                visited[nx][ny][from.cnt+1] = true;
                q.push(state(nx, ny, from.d+1, from.cnt+1));
            }
        }
    }
    cout << -1;
}