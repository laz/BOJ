#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int exps[16];
int N, r, c;

void input() {
    fastio;
    cin >> N >> r >> c;
}

void dac(int n, int x, int y, int cnt) {
    int quadCount = exps[n-1] * exps[n-1];
    int quad, nx = x, ny = y;

    if(x + exps[n-1] <= r) {
        if(y + exps[n-1] <= c){
            quad = 3; nx += exps[n-1]; ny += exps[n-1]; 
        }
        else{
            quad = 2; nx += exps[n-1];
        }
    }    
    else {
        if(y + exps[n-1] <= c) {
            quad = 1; ny += exps[n-1];
        }
        else
            quad = 0;
    }
    
    if(n == 1) {
        cout << cnt + quad * quadCount;
        exit(0);
    }
    dac(n-1, nx, ny, cnt + quad * quadCount);

}

int main() {
    input();

    exps[0] = 1;
    for(int i = 1; i < 16; ++i) 
        exps[i] = exps[i-1]*2;

    dac(N, 0, 0, 0);
}