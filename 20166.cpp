#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int cache[10][10][5][27]; // x y idx next alphabet
char map[10][10];
int n, m;
string s;

int d(int x, int y, int idx, int len){
    if(idx == len) return 1;

    int& ret = cache[x][y][idx][s[idx] - 'a'];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 8; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0) nx = n-1;
        if(nx >= n) nx = 0;
        if(ny < 0) ny = m-1;
        if(ny >= m) ny = 0;

        if(map[nx][ny] == s[idx]) ret += d(nx, ny, idx+1, len);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
    }

    while(k--){
        memset(cache, -1, sizeof(cache));
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(map[i][j] == s[0]) cnt += d(i, j, 1, s.length());
                
            }
        }
        cout << cnt << endl;
    }
    
}