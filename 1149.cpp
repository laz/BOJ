#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n, pre[3], dp[3];

int main(){
    scanf("%d", &n);
    scanf("%d %d %d", &pre[0], &pre[1], &pre[2]);
    for(int i = 1 ; i < n; i++){
        scanf("%d %d %d", &dp[0], &dp[1], &dp[2]);
        dp[0]+=min(pre[1], pre[2]);
        dp[1]+=min(pre[0], pre[2]);
        dp[2]+=min(pre[1], pre[0]);
        pre[0]=dp[0];
        pre[1]=dp[1];
        pre[2]=dp[2];
    }
    printf("%d\n", min(dp[0], min(dp[1], dp[2])));
}