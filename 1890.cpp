#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

int map[100][100];
ll cache[100][100];
int n;

ll bf(int x, int y){
    if((x == n-1) && (y == n-1)) return 1;

    ll& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 0;
    if(x + map[x][y] < n) ret += bf(x + map[x][y], y);
    if(y + map[x][y] < n) ret += bf(x, y + map[x][y]);

    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0 ; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> map[i][j];

    cout << bf(0, 0);
}