#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n, mx=0;
int tri[501], dp[501][501];

int main(){
    scanf("%d", &n);
    scanf("%d", &tri[1]);
    dp[1][1]=tri[1];
    for(int i = 2 ; i <= n; i++){
        for(int j = 1 ; j <= i; j++){
            scanf("%d", &tri[j]);
            dp[i][j]=tri[j]+max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    for(int i = 1 ; i <= n; i++)
        mx=max(mx, dp[n][i]);
    printf("%d\n", mx);

}