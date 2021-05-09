#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};

queue<pair<int, int> > viruses;
bool visited[8][8];
int arr[8][8];
int n, m, ans = 0;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                visited[i][j] = true;
                viruses.push({i, j});
            }
        }
    }
}

void bfs() {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int> > q(viruses);

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || arr[nx][ny] != 0) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!arr[i][j] && !visited[i][j]) cnt++;
        }
    }
    ans = max(ans, cnt);
}
bool dVisited[8][8];
void dfs(int x, int y, int cnt) {
    if(cnt == 0) {
        bfs();
        return ;
    }

    for(int i = x; i < n; ++i) {
        int start = 0;
        if(i == x) start = y;
        for(int j = start; j < m; ++j) {
            if(dVisited[i][j] || arr[i][j] != 0) continue;
            dVisited[i][j] = true;
            arr[i][j] = 1;
            dfs(i, j+1, cnt-1);
            dVisited[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

int main() {
    input();

    dfs(0, 0, 3);
    cout << ans;
}