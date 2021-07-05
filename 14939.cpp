#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int n = 10;
bool cache[1<<10];
bool arr[10][10];
int ans = 2e9;

void input() {
    fastio;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            char c; cin >> c;
            if(c == 'O') arr[i][j] = true;
            else arr[i][j] = false;
        }
    }
}

void click(vector<vector<bool> >& m, int x, int y) {
    m[x][y] = !m[x][y];
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        m[nx][ny] = !m[nx][ny];
    }
}

void calculate(int visited) {
    // copy
    vector<vector<bool> > m(n, vector<bool>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            m[i][j] = arr[i][j];
        }
    }
    int cnt = 0;
    // fix top
    for(int i = 0; i < n; ++i) {
        if(visited & (1 << i)) { 
            click(m, 0, i); cnt++;
        } 
    }
    // click accordingly
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(m[i-1][j]) { 
                click(m, i, j); cnt++;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(m[n-1][i]) return ;
    }
    ans = min(ans, cnt);
}

void d(int idx, int visited) {
    
    if(idx == n) {
        calculate(visited);
        return ;
    }

    if(cache[visited]) return ;
    cache[visited] = true;

    for(int i = idx; i < n; ++i) {
        d(i+1, visited | (1 << i));
        d(i+1, visited);
    }
}

int main() {
    input();
    d(0, 0);
    cout << (ans == 2e9 ? -1 : ans);
}