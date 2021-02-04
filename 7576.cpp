#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int tomato[1000][1000], days[1000][1000];
int n, m;

int main(){
    scanf("%d %d", &m, &n);
    queue<pair<int, int> > que;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j] == 1){
                que.push({i, j});
                days[i][j] = 1;
            }
            else if(tomato[i][j] == -1){
                days[i][j] = -1;
            }
        }
            
    while(!que.empty()){
        pair<int, int> curr = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int x = curr.X + dx[i], y = curr.Y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m || days[x][y]) continue;
            que.push({x, y});
            days[x][y] = days[curr.X][curr.Y] + 1;
        }
    }    
    int ret = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!days[i][j]){
                printf("-1\n");
                return 0;
            }
            ret = max(ret, days[i][j]);
        }
    }
    printf("%d\n", ret-1);
}