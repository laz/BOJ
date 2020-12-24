#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[101][100001]; // items weight 
int items[101][2]; // weight value
        
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &items[i][0], &items[i][1]);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(items[i][0]<=j)
                dp[i][j]=max(items[i][1]+dp[i-1][j-items[i][0]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d\n", dp[n][k]);
}