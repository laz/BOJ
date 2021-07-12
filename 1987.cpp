#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

unordered_set<int> cache[21][21];
int arr[21][21];
int n, m, ans = 0;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char c; cin >> c;
            arr[i][j] = c - 'A';
        }
    }
}

void d(int x, int y, int visited) {
    ans = max(ans, __builtin_popcount(visited));

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited & (1 << arr[nx][ny])) continue;
        int nVisited = (visited | (1 << arr[nx][ny]));
        if(cache[nx][ny].find(nVisited) != cache[nx][ny].end()) continue;
        cache[nx][ny].insert(nVisited);
        d(nx, ny, nVisited);
    }
}

int main() {
    fastio;
    input();
    
    cache[0][0].insert((1 << arr[0][0]));
    d(0, 0, (1 << arr[0][0]));
    cout << ans;
}