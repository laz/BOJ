#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[50][50];
int board[50][50], cache[50][50];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j) {
            if(s[j] == 'H') board[i][j] = -1;
            else board[i][j] = s[j] - '0';
        }
    }
}

int d(int x, int y) {
    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 4; ++i) {
        int offset = board[x][y];
        int nx = x + dx[i]*offset, ny = y + dy[i]*offset;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == -1) continue;
        if(visited[nx][ny]) {
            cout << -1;
            exit(0);
        }
        visited[nx][ny] = true;
        ret = max(ret, d(nx, ny)+1);
        visited[nx][ny] = false;
    }
    return ret;
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));
    visited[0][0] = true;
    cout << d(0, 0)+1;
}