#include <bits/stdc++.h>
using namespace std;

int n, mx;
int lst[1001], dp[1001];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n; i++)
        scanf("%d", &lst[i]);
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j < i; j++)
            if(lst[i]>lst[j]) 
                dp[i]=max(dp[i], dp[j]+1);
        if(dp[i]>mx) mx=dp[i];
    }
    printf("%d\n", mx+1);
}