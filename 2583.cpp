#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool map[100][100], visited[100][100];
int n, m;

int bfs(int x, int y){
    int ret = 0;
    queue<pair<int, int> > q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second; q.pop();
        ++ret;
        for(int i = 0; i < 4; ++i){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || map[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return ret;
}
int main(){
    int k;
    cin >> n >> m >> k;
    int lbx, lby, rtx, rty;
    for(int i = 0; i < k; ++i){
        cin >> lbx >> lby >> rtx >> rty;
        for(int x = lbx; x < rtx; ++x)
            for(int y = lby; y < rty; ++y)
                map[n-1-y][x] = true;
            
    }
    
    vector<int> v;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(visited[i][j] || map[i][j]) continue;
            v.push_back(bfs(i, j));
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;;
    for(int i : v)
        cout << i << " ";
}