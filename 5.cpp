#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[4] = {1, -1, 0, 0,};
int dy[4] = {0, 0, 1, -1};


struct state {
    int x, y, d, k;
    state(int xx, int yy, int dd, int kk) {
        x = xx, y = yy, d = dd, k = kk;
    }
    bool operator<(const state& s) const {
        return d > s.d;
    }
};

int dist[105][105][3];
int arr[105][105];
pii src, dst;
int n, m;

void input() {
    cin >> n >> m;
    cin >> src.first >> src.second >> dst.first >> dst.second;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    fastio;
    input();
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<state> pq;
    dist[src.first][src.second][1] = 0;
    pq.push(state(src.first, src.second, 0, 1));
    while(!pq.empty()) {
        auto [fx, fy, fd, fk] = pq.top(); pq.pop();

        if(dist[fx][fy][fk] > fd) continue;
        if(fx == dst.first && fy == dst.second) {
            cout << fd;
            return 0;
        }

        int nfk = (fk+1)%3;
        if(fk%3 == 0) {
            for(int i = 0; i < 4; ++i) {
                int nx = fx + dx[i], ny = fy + dy[i];
                int nDist = fd + arr[nx][ny];
                if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == -1) continue;
                if(dist[nx][ny][nfk] <= nDist) continue;
                dist[nx][ny][nfk] = nDist;
                pq.push(state(nx, ny, nDist, nfk));

            }
        }
        else if(fk%3 == 1) {
            for(int i = 0; i < 2; ++i) {
                int nx = fx + dx[i], ny = fy + dy[i];
                int nDist = fd + arr[nx][ny];
                if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == -1) continue;
                if(dist[nx][ny][nfk] <= nDist) continue;
                dist[nx][ny][nfk] = nDist;
                pq.push(state(nx, ny, nDist, nfk));

            }
        }
        else {
            for(int i = 2; i < 4; ++i) {
                int nx = fx + dx[i], ny = fy + dy[i];
                int nDist = fd + arr[nx][ny];
                if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == -1) continue;
                if(dist[nx][ny][nfk] <= nDist) continue;
                dist[nx][ny][nfk] = nDist;
                pq.push(state(nx, ny, nDist, nfk));

            }
        }
    }
    cout << -1;
}