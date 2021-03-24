#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[3] = {-1, 0, 1};

int map[1000][1000], cache[1000][1000][3];
int n, m;

int d(int x, int y, int dir){
    if(x == n) return 0;

    int& ret = cache[x][y][dir];
    if(ret != -1) return ret;

    ret = 1e9;
    for(int i = 0 ; i < 3; ++i){
        if(dir == i || y + dy[i] < 0 || y + dy[i] >= m) continue;
        ret = min(ret, d(x+1, y + dy[i], i) + map[x][y]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    int ans = 1e9;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 3; ++j){
            ans = min(ans, d(0, i, j));
        }
    }
    cout << ans << endl;
}