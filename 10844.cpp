#include <cstdio>

int n;
int dp[101][11];
long long sum=0;
int main(){
    for(int i = 0 ; i < 10; i++)
        dp[1][i]=1;
    scanf("%d", &n);
    for(int i = 2 ; i <= n; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][9]=dp[i-1][8];
        for(int j = 1; j < 9; j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
    }
    for(int i = 1; i < 10; i++)
        sum+=dp[n][i];
    printf("%lld\n", sum%1000000000);
}