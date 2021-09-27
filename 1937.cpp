#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int arr[501][501], cache[501][501];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

int dfs(int x, int y, int dist) {

    int& ret = cache[x][y];
    if(ret != -1) return ret;

    int mx = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(arr[nx][ny] <= arr[x][y]) continue;

        if(cache[nx][ny] != -1) {
            mx = max(mx, cache[nx][ny] + 1);
            continue;
        }
        mx = max(mx, dfs(nx, ny, dist + 1) + 1);
    }
    return ret = mx;
}

int main() {
    fastio;
    input();
    memset(cache, -1, sizeof(cache));

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans = max(ans, dfs(i, j, 0));
        }
    }
    cout << ans+1;
}