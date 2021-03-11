#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int map[50][50], visited[50][50];
int n, m;

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || !map[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, k, a, b;
    cin >> t;
    while(t--){
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> m >> n >> k;
        for(int i = 0; i < k; ++i){
            cin >> a >> b;
            map[b][a] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!map[i][j] || visited[i][j]) continue;
                cnt++;
                bfs(i, j);
            }
        }
        cout << cnt << "\n";
    }
}