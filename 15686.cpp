#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[50][50];
bool visited[50][50];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > chicken;
    vector<pair<int, int> > houses;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> map[i][j];
            if(map[i][j] == 1) houses.push_back({i, j});
            else if(map[i][j] == 2) chicken.push_back({i, j});
        }
    }

    int nOfChicken = chicken.size();
    vector<int> a(nOfChicken, 0);
    for(int i = m; i < nOfChicken; ++i){
        a[i] = 1;
    }
    int ans = 2e9;
    do{
        int nmap[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                nmap[i][j] = map[i][j];
            }
        }
        for(int i = 0; i < nOfChicken; ++i){
            int x = chicken[i].first, y = chicken[i].second;
            if(a[i]) nmap[x][y] = 0;
        }
        int dist = 0;
        
        for(auto& p : houses){
            queue<pair<int, int> > q;
            memset(visited, false, sizeof(visited));
            q.push(p);
            visited[p.first][p.second] = true;
            bool found = false;
            while(!q.empty() && !found){
                int x = q.front().first, y = q.front().second; q.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    if(nmap[nx][ny] == 2){
                        dist += abs(p.first - nx) + abs(p.second - ny);
                        found = true;
                        break;
                    }
                    q.push({nx, ny});
                }
            }
        }
        ans = min(ans, dist);
        
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;
}