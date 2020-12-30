#include <bits/stdc++.h>
using namespace std;

int n;
int nova[2190][2190], ans[3];

int novatree(int depth, int y, int x){
    
    if(depth == 1){
        ans[nova[y][x]+1]++;
        return nova[y][x];
    }
    int nextDepth = depth/3;
    int midX[3], midY[3];
    midX[0] = x;
    midY[0] = y;
    midX[1] = x+nextDepth;
    midX[2] = x+nextDepth*2;
    midY[1] = y+nextDepth;
    midY[2] = y+nextDepth*2;

    int p[3][3];
    for(int i = 0 ; i < 3; ++i){
        for(int j = 0 ; j < 3; ++j){
            p[i][j] = novatree(depth/3, midY[i], midX[j]);
        }
    }
    bool allm1 = true, all0 = true, all1 = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            if(p[i][j] != -1) allm1 = false;
            if(p[i][j] != 0) all0 = false;
            if(p[i][j] != 1) all1 = false;
        }
    }
    if(allm1){
        ans[0] -= 8;
        return -1;
    }
    else if(all0){
        ans[1] -= 8;
        return 0;
    }
    else if(all1){
        ans[2] -= 8;
        return 1;
    }
    else{
        return -2;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i){
        for(int j = 0 ; j < n; ++j){
            scanf("%d", &nova[i][j]);
        }
    }
    novatree(n, 0, 0);
    for(int i = 0 ; i < 3; ++i)
        printf("%d\n", ans[i]);
}