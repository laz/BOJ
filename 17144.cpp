#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> purifier;
int arr[51][51];
int n, m, t, ans = 0;

struct dust {
    int x, y, value;
    dust(int a, int b, int c) {
        x = a, y = b, value = c;
    }
};

void input() {
    fastio;
    cin >> n >> m >> t;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) {
                purifier = {i-1, i};
            }
            else {
                ans += arr[i][j];
            }
        }
    }
}

void diffuse() {
    // find 
    queue<dust> q;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
            if(arr[i][j]) q.push(dust(i, j, arr[i][j]));
        
    // diffuse
    while(!q.empty()) {
        dust src = q.front(); q.pop();
        int blown = 0;
        for(int i = 0; i < 4; ++i) {
            int nx = src.x + dx[i], ny = src.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == -1) continue;
            arr[nx][ny] += src.value/5;
            blown += src.value/5;
        }
        arr[src.x][src.y] -= blown;
    }
}

void purify() {
    // upper
    ans -= arr[purifier.first-1][0];
    for(int i = purifier.first-2; i >= 0; --i) {
        arr[i+1][0] = arr[i][0];
    }
    for(int i = 1; i < m; ++i) {
        arr[0][i-1] = arr[0][i];
    }
    for(int i = 1; i <= purifier.first; ++i) {
        arr[i-1][m-1] = arr[i][m-1];
    }
    for(int i = m-2; i > 0; --i) {
        arr[purifier.first][i+1] = arr[purifier.first][i];
    }
    arr[purifier.first][1] = 0;

    // lower
    ans -= arr[purifier.second+1][0];
    for(int i = purifier.second+2; i < n; ++i) {
        arr[i-1][0] = arr[i][0];
    }
    for(int i = 1; i < m; ++i) {
        arr[n-1][i-1] = arr[n-1][i];
    }
    for(int i = n-2; i >= purifier.second; --i) {
        arr[i+1][m-1] = arr[i][m-1];
    }
    for(int i = m-2; i > 0; --i) {
        arr[purifier.second][i+1] = arr[purifier.second][i];
    }
    arr[purifier.second][1] = 0;
}

int main() {
    input();

    while(t--) {
        diffuse();
        purify();
    }
    cout << ans;
}