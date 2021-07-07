#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool visited[51][51];
int arr[51][51];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            arr[i][j] = s[j] - 'A';
        }
    }
}

bool d(int fx, int fy, int x, int y, int cnt, int color) {
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(nx == fx && ny == fy && cnt >= 4) return true;
        if(visited[nx][ny] || arr[nx][ny] != color) continue;
        visited[nx][ny] = true;
        if(d(fx, fy, nx, ny, cnt+1, color)) return true;
    }
    return false;
}

int main() {
    fastio;
    input();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            memset(visited, false, sizeof(visited));
            visited[i][j] = true;
            if(d(i, j, i, j, 1, arr[i][j])) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}