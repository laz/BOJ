#include <bits/stdc++.h>
using namespace std;

int mn = numeric_limits<int>::max();

int n, n2;
int stat[20][20];
int t1[10], t2[10];
bool toggle[20];


void travel(int cnt){
    if(cnt == n2){
        int cnt2 = 0;
        for(int i = 0 ; i < n; ++i)
            toggle[i] = false;
        for(int i = 0 ; i < n2; ++i)
            toggle[t1[i]] = true;
        for(int i = 0; i < n; ++i)
            if(!toggle[i]) t2[cnt2++] = i;

        int stat1 = 0, stat2 = 0;
        for(int i = 0 ; i < n2; ++i){
            for(int j = i+1 ; j < n2; ++j){
                stat1 += stat[t1[i]][t1[j]] + stat[t1[j]][t1[i]];
                stat2 += stat[t2[i]][t2[j]] + stat[t2[j]][t2[i]];
            }
        }
        mn = min(mn, abs(stat1-stat2));
        return ;
    }

    for(int i = 0 ; i < n; ++i){
        if(cnt >= 1 && t1[cnt-1] >= i) continue;
        t1[cnt]=i;
        travel(cnt+1);
        t1[cnt]=0;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &stat[i][j]);
    n2 = n/2;
    for(int i = 0 ; i < n/2; ++i)
        t1[i]=-1;
    travel(0);
    printf("%d\n", mn);
}