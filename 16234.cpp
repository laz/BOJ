#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pii> lst[2500];
int arr[50][50], color[50][50], sum[2500];
int n, l, r;

void input() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

void bfs(int ix, int iy, int c) {
    queue<pii> q;
    color[ix][iy] = c;
    q.push({ix, iy});

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        lst[c].push_back({x, y});
        sum[c] += arr[x][y];

        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || color[nx][ny] != -1) continue;

            int diff = abs(arr[x][y] - arr[nx][ny]);
            if(diff < l || diff > r) continue;
            color[nx][ny] = c;
            q.push({nx, ny});
        }
    }
}

void relocation(int mx) {

    for(int c = 0; c < mx; ++c) {
        int pop = sum[c] / lst[c].size();
        for(auto& v : lst[c]) {
            arr[v.first][v.second] = pop;
        }
    }
}

int main() {
    fastio;
    input();

    int ans = 0;
    while(1) {
        memset(color, -1, sizeof(color));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n*n; ++i) lst[i].clear();
        // find union
        int c = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(color[i][j] == -1) bfs(i, j, c++);
            }
        }
        if(c == n*n) break;
        relocation(c);
        ans++;
    }
    cout << ans;
}