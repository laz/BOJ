#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[100][100];
char arr[100][100];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];
}

void bfs(int x, int y, bool colorBlind) {
    queue<pair<int, int> > q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        char cc = arr[cx][cy]; 
        for(int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            // color
            char nc = arr[nx][ny];
            if(colorBlind) {
                if(cc == 'G') cc = 'R';
                if(nc == 'G') nc = 'R';
            }  
            if(cc != nc) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int b(bool colorBlind) {
    int ret = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(visited[i][j]) continue;
            bfs(i, j, colorBlind);
            ret++;
        }
    }
    return ret;
}

int main() {
    input();
    cout << b(false) << " ";
    memset(visited, false, sizeof(visited));
    cout << b(true);
}