#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int labyrinth[100][100], dist[100][100];

int main(){
    int n, m;
    cin >> n >> m;
    string tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        for(int j = 0; j < m; ++j)
            labyrinth[i][j] = tmp[j] - '0';
    }

    bool notFound = true;
    queue<pair<int, int> > que;
    que.push({0, 0});
    dist[0][0] = 1;
    while(notFound){
        pair<int, int> curr = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int x = curr.X + dx[i];
            int y = curr.Y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(dist[x][y] || !labyrinth[x][y]) continue;
            que.push({x, y});
            dist[x][y] = dist[curr.X][curr.Y] + 1;
            if(x == n-1 && y == m-1) notFound = false;
        }
    }
    printf("%d\n", dist[n-1][m-1]);
}