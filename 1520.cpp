#include <cstdio>
#include <cstring>
using namespace std;

int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};
int map[502][502], cache[502][502];
int n, m;

int findPath(int y, int x){
    //Base case
    if(y == n-1 && x == m-1)
        return 1;
    if(y >= n || x >= m || y < 0 || x < 0)
        return 0;
    
    int& ret = cache[y][x];
    //printf("%d %d: %d\n", y, x, map[y][x]);
    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = 0; i < 4; ++i)
        if(map[y+dy[i]][x+dx[i]] < map[y][x])
            ret += findPath(y+dy[i], x+dx[i]);
    
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; ++i)
        for(int j = 0 ; j < m; ++j)
            scanf("%d", &map[i][j]);
    memset(cache, -1, sizeof(cache));
    printf("%d\n", findPath(0, 0));
}