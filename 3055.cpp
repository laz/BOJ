#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct point{
    int x, y, time;
    point(int a, int b, int c) {
        x = a; y = b; time = c;
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<point> q;
vector<point> water;
char arr[50][50];
int visited[50][50];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        for(int j = 0; j < m; ++j) {
            if(arr[i][j] == 'S') {
                visited[i][j] = 1;
                q.push(point(i, j, 0));
            }
            else if(arr[i][j] == '*') water.push_back((point(i, j, -1)));
        }
    }
}

void b() {
    while(!q.empty()) {
        point p = q.front(); q.pop();
        if(p.time >= 0 && visited[p.x][p.y] == -1) continue;
        for(int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 'X' || visited[nx][ny] < 0) continue;

            // 고슴도치
            if(p.time >= 0) {
                if(arr[nx][ny] == 'D') {
                    cout << p.time+1;
                    exit(0);
                }
                if(visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                q.push(point(nx, ny, p.time + 1));
            } else {
                if(arr[nx][ny] == 'D') continue;
                visited[nx][ny] = -1;
                q.push(point(nx, ny, -1));
            }
        }
    }
}

int main() {
    input();

    for(auto w : water) {
        visited[w.x][w.y] = -1;
        q.push(w);
    }
    b();
    cout << "KAKTUS";
}