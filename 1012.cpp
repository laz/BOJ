#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, k;
        scanf("%d %d %d", &m, &n, &k);
        int map[n][m];
        int x, y;
        memset(map, 0, sizeof(map));
        for(int i = 0; i < k; ++i){
            scanf("%d %d", &y, &x);
            map[x][y] = 1;
        }
        bool visited[n][m];
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int> > q;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!map[i][j] || visited[i][j]) continue;
                cnt++;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    for(int k = 0; k < 4; ++k){
                        int x = curr.X + dx[k], y = curr.Y + dy[k];
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        if(!map[x][y] || visited[x][y]) continue;
                        q.push({x, y});
                        visited[x][y] = true;;
                    }
                }
            }
        }
        printf("%d\n", cnt);

    }
}