#include <cstdio>

int t, num, dp[41][2], zeros, ones;

int main(){

    dp[0][0]=1;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i = 2 ; i < 41; i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
        dp[i][1]=dp[i-1][1]+dp[i-2][1];
    }
    scanf("%d", &t);
    for(int i = 0 ; i < t; i++){
        scanf("%d", &num);
        printf("%d %d\n", dp[num][0], dp[num][1]);
    }
}