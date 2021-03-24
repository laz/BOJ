#include <iostream>
using namespace std;

int map[101][101];
bool res[101][101]; //  0 S 1 F


int main(){
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> map[i][j];
        
    int x, y, tot = 0;
    char d;
    
    while(r--){
        cin >> x >> y >> d;

        int cnt = map[x][y], idx = 0, dx = 0, dy = 0;

        if(res[x][y]) cnt = 0;
        if(d == 'E') dy = 1;
        else if(d == 'W') dy = -1;
        else if(d == 'S') dx = 1;
        else if(d == 'N') dx = -1;
        
        while(cnt){
            if(x < 1 || x > n || y < 1 || y > m) break;
            
            if(res[x][y] == 0){
                res[x][y] = true;
                tot++;
                if(cnt < map[x][y]) cnt = map[x][y];
            }
            x += dx; y += dy;
            cnt--;
        }
        
        cin >> x >> y;
        res[x][y] = false;

    }
    cout << tot << "\n";
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(res[i][j] == 0) cout << "S ";
            else cout << "F ";
        }
        cout << endl;
    }

}