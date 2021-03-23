#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[1000][1000], cache[1000][1000];
int n, m;

int d(int x, int y){
    if(x == n && y == m) return map[x][y];

    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 0;
    if(x+1 < n) ret = d(x+1, y);
    if(y+1 < m) ret = max(ret, d(x, y+1));
    if(x+1 < n && y+1 < m) ret = max(ret, d(x+1, y+1));

    return ret += map[x][y];
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
    cout << d(0, 0);
}