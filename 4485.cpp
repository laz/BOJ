#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[125][125], visited[125][125];
int n;

int d(){
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {0, 0}});
    visited[0][0] = 0;

    while(!pq.empty()){

        int cost = -pq.top().first, fx = pq.top().second.first, fy = pq.top().second.second;
        pq.pop();
        if(cost > visited[fx][fy]) continue;

        for(int i = 0; i < 4; ++i){
            int nx = fx + dx[i], ny = fy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] != -1) continue;

            int nCost = cost + map[nx][ny];
            if((nx == n-1) && (ny == n-1)) return nCost;

            pq.push({-(cost + map[nx][ny]), {nx, ny}});
            visited[nx][ny] = cost + map[nx][ny];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int p = 1;
    while(cin >> n){
        if(!n) return 0;
        memset(map, 0, sizeof(map));
        memset(visited, -1, sizeof(visited));

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> map[i][j];

        cout << "Problem " << p++ << ": " << d() + map[0][0] << "\n";
    }
}