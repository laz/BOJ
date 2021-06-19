#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool map[101][101], visited[101][101];
int n, m;

int bfs(int x, int y){
    int ret = 0;
    queue<pair<int, int> > q;
    visited[x][y] = 1;
    q.push({x, y});
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        ret++;
        for(int i = 0; i < 4; ++i){
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || map[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return ret;
}

int main(){
    
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
        }
    }
    int total = n*m;
    int time = 0, cheese;
    while(1){
        memset(visited, false, sizeof(visited));
        int air = bfs(0, 0);
        if(air == total) break;
        time++;

        cheese = 0;
        queue<pair<int, int> > cheeses;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(map[i][j]) {
                    //치즈 세고
                    cheese++;
                    //녹아 없어지는 치즈 색출
                    for(int k = 0; k < 4; ++k){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(!map[nx][ny] && visited[nx][ny]){
                            cheeses.push({i, j});
                            break;
                        }
                    }
                }
            }
        }
        //치즈 녹이기
        while(!cheeses.empty()){
            auto c = cheeses.front(); cheeses.pop();
            map[c.first][c.second] = 0;
        }
    }
    cout << time << "\n" << cheese;

}