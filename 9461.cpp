#include <cstdio>

int t, num;
long long dp[100]={1, 1, 1, };

int main(){
    for(int i = 3 ; i < 100; i++)
        dp[i]=dp[i-3]+dp[i-2];
    scanf("%d", &t);
    for(int i = 0 ; i < t; i++){
        scanf("%d", &num);
        printf("%lld\n", dp[num-1]);
    }
}