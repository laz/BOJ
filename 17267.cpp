#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pii p;
int dist[1005][1005];
bool arr[1005][1005];
int n, m, L, R;

struct state {
    int x, y, d, l, r;
    state(int xx, int yy, int dd, int ll, int rr) {
        x = xx, y = yy, d = dd, l = ll, r = rr;
    }
};

void input() {
    cin >> n >> m >> L >> R;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            if(s[j] == '2') {
                p = {i, j};
                arr[i][j] = 0;
            }
            else arr[i][j] = s[j] - '0';
        }
    }
}

int main() {
    fastio;
    input();
    memset(dist, -1, sizeof(dist));

    int ans = 0;
    queue<state> q;
    dist[p.first][p.second] = 0;
    q.push(state(p.first, p.second, 0, 0, 0));
    while(!q.empty()) {
        auto [x, y, d, l, r] = q.front(); q.pop();
        ans++;
        // up
        for(int nx = x-1; nx >= 0 && !arr[nx][y]; --nx) {
            if(arr[nx][y] || dist[nx][y] != -1) break;
            dist[nx][y] = d;
            q.push(state(nx, y, d, l, r));
        }

        // down
        for(int nx = x+1; nx < n && !arr[nx][y]; ++nx) {
            if(arr[nx][y] || dist[nx][y] != -1) break;
            dist[nx][y] = d;
            q.push(state(nx, y, d, l, r));
        }

        // left
        if(l < L) {
            if(!arr[x][y-1] && dist[x][y-1] == -1 && y-1 >= 0) {
                dist[x][y-1] = d+1;
                q.push(state(x, y-1, d+1, l+1, r));
            }
        }
        // right
        if(r < R) {
            if(!arr[x][y+1] && dist[x][y+1] == -1 && y+1 < m) {
                dist[x][y+1] = d+1;
                q.push(state(x, y+1, d+1, l, r+1));
            }
        }
    }
    cout << ans;
}