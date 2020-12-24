#include <bits/stdc++.h>
using namespace std;

int n, mx, dp[2];
int main(){
    scanf("%d %d", &n, &dp[1]);
    mx=dp[1];
    for(int i = 2 ; i <= n; i++){
        scanf("%d", &dp[i%2]);
        if(dp[(i-1)%2]+dp[i%2]>0 && dp[(i-1)%2]>0) dp[i%2]+=dp[(i-1)%2];
        if(mx<dp[i%2]) mx=dp[i%2];
    }
    printf("%d\n", mx);
}