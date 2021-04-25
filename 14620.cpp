#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[10][10];
int arr[10][10];
int n, ans = 0;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];
}

bool able(int x, int y) {
    if(visited[x][y]) return false;
    for(int i = 0; i < 4; ++i) {
        if(visited[x + dx[i]][y + dy[i]]) return false;
    }
    return true;
}

void bloom(int x, int y, bool flag) {
    visited[x][y] = flag;
    for(int i = 0; i < 4; ++i) {
        visited[x + dx[i]][y + dy[i]] = flag;
    }
}

int cost(int x, int y) {
    int ret = arr[x][y];
    for(int i = 0; i < 4; ++i) {
        ret += arr[x + dx[i]][y + dy[i]];
    }
    return ret;
}

int d(int cnt) {

    if(cnt == 3) return 0;

    int ret = 1e9;
    for(int i = 1; i < n-1; ++i) {
        for(int j = 1; j < n-1; ++j) {
            if(!able(i, j)) continue;
            bloom(i, j, true);
            ret = min(ret, d(cnt+1) + cost(i, j));
            bloom(i, j, false);
        }
    }
    return ret;
}

int main() {
    input();
    cout << d(0);
}