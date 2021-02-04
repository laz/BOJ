#include <cstdio>
#include <queue>
using namespace std;

struct point{
    int x, y, z;
    point(int zz, int xx, int yy){
        x = xx; y = yy; z = zz;
    }
};

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int map[101][101][101], dist[101][101][101];

int main(){
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    queue<point> q;
    for(int k = 0; k < h; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                scanf("%d", &map[k][i][j]);
                if(map[k][i][j] == 1){
                    q.push(point(k, i, j));
                    dist[k][i][j] = 1;
                }
                else if(map[k][i][j] == -1)
                    dist[k][i][j] = -1;
            }
        }
    }
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        for(int l = 0; l < 6; ++l){
            int x = curr.x + dx[l], y = curr.y + dy[l], z = curr.z + dz[l];
            if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h) continue;
            if(dist[z][x][y]) continue;
            dist[z][x][y] = dist[curr.z][curr.x][curr.y] + 1;
            q.push(point(z, x, y));
        }
    }
    int ret = 0;
    for(int k = 0; k < h; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!dist[k][i][j] && map[k][i][j] != -1){
                    printf("-1\n");
                    return 0;
                }
                ret = max(ret, dist[k][i][j]);
            }
        }
    }
    printf("%d\n", ret-1);
}