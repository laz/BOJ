#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[1001][1001], dist[1001][1001][2];
int n, m;

void bfs(int x, int y, int z){
    queue<tuple<int, int ,int> > q;
    dist[x][y][z] = 1;
    q.push({x, y, z});
    while(!q.empty()){
        int currX, currY, currZ;
        tie(currX, currY, currZ) = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = currX + dx[i], ny = currY + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(nx == n-1 && ny == m-1){
                cout << dist[currX][currY][currZ] + 1;
                return ;
            }
            //코인 미사용, 벽 && 0층
            if(map[nx][ny] && !currZ){
                dist[nx][ny][1] = dist[currX][currY][currZ] + 1;
                q.push({nx, ny, 1});
            }
            if(map[nx][ny] || dist[nx][ny][currZ]) continue;
            dist[nx][ny][currZ] = dist[currX][currY][currZ] + 1;
            q.push({nx, ny, currZ});
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    if(n == 1 && m == 1){
        cout << 1;
        return 0;
    }
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j)
            map[i][j] = s[j] - '0';
    }
    bfs(0, 0, 0);
}