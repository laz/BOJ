#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10001], wine[10001];

int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ;i++)
        scanf("%d", &wine[i]);
    dp[1]=wine[1];
    dp[2]=dp[1]+wine[2];
    dp[3]=max(dp[2], max(wine[3]+wine[2], wine[3]+wine[1]));
    for(int i = 4 ; i <= n ;i++)
        dp[i]=max(wine[i]+wine[i-1]+dp[i-3], max(wine[i]+dp[i-2], dp[i-1]));
    printf("%d\n", dp[n]);   
}
