#include <bits/stdc++.h>
using namespace std;

struct point{
    int y;
    int x;
    point(int yy, int xx){
        y = yy;
        x = xx;
    }
};

const int n = 9;
int sudoku[n][n];
vector<point> empties;

bool isValid(point& p, int num){
    
    for(int i = 0 ; i < n; ++i){
        if(sudoku[p.y][i] == num) return false;
    }
    for(int i = 0 ; i < n; ++i){
        if(sudoku[i][p.x] == num) return false;
    }
    int y0 = p.y/3*3;
    int x0 = p.x/3*3;
    for(int i = y0; i < y0+3; ++i){
        for(int j = x0; j < x0+3; ++j){
            if(sudoku[i][j] == num) return false;
        }
    }
    return true;
}

void solve(int idx){
    if(idx >= empties.size()){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    
    point p = empties[idx];
    for(int i = 1; i <= n; ++i){
        if(isValid(p, i)){
            sudoku[p.y][p.x] = i;
            solve(idx+1);
            sudoku[p.y][p.x] = 0;
        }
    }
}

int main(){
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &sudoku[i][j]);
            if(sudoku[i][j] == 0){
                empties.push_back(point(i, j));
            }
        }
    }
    solve(0);
}