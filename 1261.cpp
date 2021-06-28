#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[101][101], dist[101][101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> m >> n;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j)
            map[i][j] = s[j] - '0';
    }
    memset(dist, -1, sizeof(dist));
    int x, y;
    queue<pair<int, int> >q;
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()){
        x = q.front().first; y = q.front().second; q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!map[nx][ny]){
                if(dist[nx][ny] <= dist[x][y] && dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y];
                q.push({nx, ny});
            }
            else if(map[nx][ny]){
                if(dist[nx][ny] <= dist[x][y]+1 && dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[n-1][m-1];
}