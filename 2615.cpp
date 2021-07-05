#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int n = 19;
int b[n][n];

void input() {
    fastio;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) 
            cin >> b[i][j];
}

bool done(int x, int y, int dir, int color) {
    // right
    if(dir == 0) {
        if(y > 14) return false;
        if(b[x][y] == color && b[x][y+1] == color && b[x][y+2] == color && b[x][y+3] == color && b[x][y+4] == color) {
            if((y+5 >= 19 || b[x][y+5] != color) && (y-1 < 0 || b[x][y-1] != color)) return true; 
        }
    }
    // down
    else if(dir == 1) {
        if(x > 14) return false;
        if(b[x][y] == color && b[x+1][y] == color && b[x+2][y] == color && b[x+3][y] == color && b[x+4][y] == color) {
            if((x+5 >= 19 || b[x+5][y] != color) && (x-1 < 0 || b[x-1][y] != color)) return true;
        }
    }
    // rd diag
    else if(dir == 2) {
        if(x > 14 || y > 14) return false;
        if(b[x][y] == color && b[x+1][y+1] == color && b[x+2][y+2] == color && b[x+3][y+3] == color && b[x+4][y+4] == color) {
            if(((y+5 >= 19 && x+5 >= 19) || b[x+5][y+5] != color) && ((y-1 < 0 && x-1 < 0) || b[x-1][y-1] != color)) return true;
        }
    }
    // ld diag
    else {
        if(y < 4 || x > 14) return false;
        if(b[x][y] == color && b[x+1][y-1] == color && b[x+2][y-2] == color && b[x+3][y-3] == color && b[x+4][y-4] == color) {
            if(((y-5 < 0 && x+5 >= 19) || b[x+5][y-5] != color) && ((y+1 >= 19 && x-1 < 0) || b[x-1][y+1] != color)) return true;
        }
    }
    return false;
}

int main() {
    input();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int color = 1; color <= 2; ++color) {
                for(int dir = 0; dir < 4; ++dir) {
                    if(done(i, j, dir, color)) {
                        cout << color << "\n";
                        ++i, ++j;
                        if(dir == 3) cout << i+4 << " " << j-4;
                        else cout << i << " " << j;
                        return 0;
                    }
                }
            }
            
        }
    }
    cout << 0;
}