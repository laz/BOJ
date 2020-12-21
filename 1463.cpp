#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int makeOne(int n){

    if(n == 1)
        return 0;
    else
    {
        if (dp[n] > 0)
        {
            return dp[n];
        }
        
        if (n%3==0)
        {
            dp[n] = min(makeOne(n/3)+1, makeOne(n-1)+1);
            //printf("%d - %d %d - %d\t%d %d\n", n, n/3, n-1, dp[n], makeOne(n/3)+1, makeOne(n-1)+1);
            return dp[n];
        }
        else if (n%2==0)
        {
            dp[n] = min(makeOne(n/2)+1, makeOne(n-1)+1);
            //printf("%d - %d %d - %d\t%d %d\n", n, n/2, n-1, dp[n], makeOne(n/2)+1, makeOne(n-1)+1);
            return dp[n];
        }
        else
        {
            dp[n] = makeOne(n-1)+1;
            //printf("%d - just %d - %d\t%d\n", n, n-1, dp[n], makeOne(n-1)+1);
            return dp[n];
        }
    }
    
}

int main(){

    int n, count;
    scanf("%d", &n);
    makeOne(n);
    printf("%d\n", dp[n]);
}