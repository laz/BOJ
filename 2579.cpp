#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int stairs[301], dp[301];
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &stairs[i]);
    dp[0]=stairs[0];
    dp[1]=stairs[0]+stairs[1];
    dp[2]=stairs[2]+max(stairs[0], stairs[1]);
    for(int i = 3 ; i < n; i++)
        dp[i]=stairs[i]+max(dp[i-2], dp[i-3] + stairs[i-1]);
    printf("%d\n", dp[n-1]);
}