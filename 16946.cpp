#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> colors;
int arr[1000][1000], color[1000][1000];
bool visited[1000][1000];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
}

int bfs(int x, int y, int c) {
    int ret = 0;

    queue<pii> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        color[cx][cy] = c;
        ret++;
        for(int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || arr[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    colors.push_back(ret);
    return ret;
}

int main() {
    input();
    memset(color, -1, sizeof(color));
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(visited[i][j] || arr[i][j]) continue;
            int cnt = bfs(i, j, idx++);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(arr[i][j] == 0) continue;
            vector<bool> check(colors.size(), false);
            for(int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(arr[nx][ny] || check[color[nx][ny]]) continue;
                check[color[nx][ny]] = true;
                arr[i][j] += colors[color[nx][ny]];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << arr[i][j] % 10;
        }
        cout << "\n";
    }
}