#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

pii p;
vector<int> h;
bool visited[51][51];
char arr[51][51];
int height[51][51];
int n, k;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < n; ++j) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'P') p = {i, j};
            else if(arr[i][j] == 'K') k++;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> height[i][j];
            h.push_back(height[i][j]);
        }
    }
}

bool bfs(int s, int e) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    if(height[p.first][p.second] < s || height[p.first][p.second] > e) return false;

    queue<pii> q;
    visited[p.first][p.second] = true;
    q.push(p);
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if(height[nx][ny] < s || height[nx][ny] > e) continue;

            if(arr[nx][ny] == 'K') {
                cnt++;
                if(cnt >= k) return true;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return false;
}

int main() {
    fastio;
    input();
    
    sort(all(h));
    int s = 0, e = 0, ans = 1e9;
    while(1) {
        if(bfs(h[s], h[e])) {
            int diff = h[e] - h[s];
            ans = min(ans, diff);
            s++;
        }
        else if(e >= n*n) break;
        else e++;
    }
    cout << ans;
}