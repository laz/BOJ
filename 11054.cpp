#include <bits/stdc++.h>
using namespace std;

int n, bit;
int lst[1001], dp[1001], lis[1001], lds[1001];

int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++)
        scanf("%d", &lst[i]);
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j < i; j++)
            if(lst[i]>lst[j])
                dp[i]=max(dp[i], dp[j]+1);
        lis[i]=dp[i];
    }
    for(int i = 1 ; i <= n; i++)
        dp[i]=0;
    for(int i = n ; i >= 1; i--){
        for(int j = n ; j > i; j--)
            if(lst[i]>lst[j])
                dp[i]=max(dp[i], dp[j]+1);
        lds[i]=dp[i];
    }
    for(int i = 1 ; i <= n; i++)
        bit=max(bit, lis[i]+lds[i]);
    printf("%d\n", bit+1);
}