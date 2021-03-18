#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int d[4][2][9] = {
    {
        {-2, -1, -1, -1, 0, 1, 1, 1, 2},
        {0, -1, 0, 1, -2, -1, 0, 1, 0,}
    },
    {
        {0, 1, 0, -1, 2, 1, 0, -1, 0},
        {-2, -1, -1, -1, 0, 1, 1, 1, 2}
    },
    {
        {2, 1, 1, 1, 0, -1, -1, -1, -2},
        {0, 1, 0, -1, 2, 1, 0, -1, 0}
    },
    {
        {0, -1, 0, 1, -2, -1, 0, 1, 0,},
        {2, 1, 1, 1, 0, -1, -1, -1, -2}
    }
};

int r[9] = {2, 10, 7, 1, 5, 10, 7, 1, 2};

int map[500][500];
int n;

void scatter(int x, int y, int direction){

    if(!map[x][y]) return ;

    int alpha = map[x][y];

    if(map[x][y] >= 10){
        for(int i = 0; i < 9; ++i){
            int dx = d[direction][0][i], dy = d[direction][1][i];
            int nx = dx + x, ny = dy + y;

            int moved = map[x][y] * (float)r[i] / 100;

            if((0 <= nx && nx < n) && (0 <= ny && ny < n)) map[nx][ny] += moved;

            alpha -= moved;
        }
    }

    int nx = x + dx[direction], ny = y + dy[direction];
    if((0 <= nx && nx < n) && (0 <= ny && ny < n)) map[nx][ny] += alpha;
    map[x][y] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> map[i][j];
            ans += map[i][j];
        }
    }

    int x = n/2, y = n/2, cnt = 0;
    for(int i = 0; i < n/2; ++i){
        for(int j = 0; j < 4; ++j){
            if(j%2 == 0) cnt++;
            for(int k = 0; k < cnt; ++k){
                x += dx[j];
                y += dy[j];
                scatter(x, y, j);
            }
        }
    }
    
    for(int i = 0; i < cnt; ++i)
        scatter(x, --y, 0);
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ans -= map[i][j];

    cout << ans;
}