#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[301][301], ice[301][301];
int map[301][301];
int n, m;

int bfs(queue<pair<int, int> >& lst){
    memset(visited, false, sizeof(visited));
    auto from = lst.front(); lst.pop();
    queue<pair<int, int> > q;
    visited[from.first][from.second] = true;;
    q.push(from);
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        for(int i = 0 ; i < 4; ++i){
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!map[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    while(!lst.empty()){
        auto left = lst.front(); lst.pop();
        if(!visited[left.first][left.second])
            return 1;
    }
    return 0; 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
            if(map[i][j]) ice[i][j] = true;
        }
    }
    int cnt = 1;
    while(1){
        bool done = true;
        // 녹이기
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!ice[i][j]) continue;
                for(int dir = 0 ; dir < 4; ++dir){
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(ice[nx][ny] || !map[i][j]) continue;
                    map[i][j]--;
                }
            }
        }
        
        memset(ice, false, sizeof(ice));
        queue<pair<int, int> > lst;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(map[i][j]) {
                    lst.push({i, j});
                    ice[i][j] = true;
                    done = false;
                }
            }
        }
        if(done) break;
        if(bfs(lst)){
            cout << cnt;
            return 0;
        }
        cnt++;
    }
    cout << 0;
}