#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool arr[101][101], exposed[101][101];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
            cin >> arr[i][j];
}

int bfs() {
    int ret = 0;

    memset(exposed, false, sizeof(exposed));
    exposed[0][0] = true;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ret++;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(exposed[nx][ny] || arr[nx][ny]) continue;
            exposed[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return ret;
}

void melt() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!arr[i][j]) continue;
            int cnt = 0;
            for(int k = 0; k < 4; ++k) {
                if(exposed[i+dx[k]][j+dy[k]]) cnt++;
                if(cnt > 1) break;
            }
            if(cnt > 1) arr[i][j] = 0;
        }
    }
}

int main() {
    input();

    int ans = 0;
    while(bfs() < n*m) {
        melt();
        ans++;
    }
    cout << ans;
}