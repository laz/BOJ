#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct state {
    int x, y, d, keys;
    state(int xx, int yy, int dd, int kk) {
        x = xx, y = yy, d = dd, keys = kk;
    }
};

pii p;
int dist[51][51][1<<6];
char arr[51][51];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            arr[i][j] = s[j];
            if(arr[i][j] == '0') p = {i, j};
        }
    }
}

int main() {
    fastio;
    input();
    memset(dist, -1, sizeof(dist));

    queue<state> q;
    dist[p.first][p.second][0] = 0;
    q.push(state(p.first, p.second, 0, 0));
    while(!q.empty()) {
        auto [x, y, d, keys] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            int nKeys = keys, nDist = d+1;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '#') continue;
            if(arr[nx][ny] == '1') {
                cout << nDist;
                return 0;
            }

            // if no key
            if('A' <= arr[nx][ny] && arr[nx][ny] <= 'F' && !(nKeys & (1 << (arr[nx][ny] - 'A'))) ) continue; 
            // obtain key
            if('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') nKeys |= (1 << (arr[nx][ny] - 'a'));

            if(dist[nx][ny][nKeys] != -1 && dist[nx][ny][nKeys] <= nDist) continue;
            dist[nx][ny][nKeys] = nDist;
            q.push(state(nx, ny, nDist, nKeys));
        }
    }
    cout << -1;
}