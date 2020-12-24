#include <bits/stdc++.h>
using namespace std;

struct line{
    int l;
    int r;
};

bool cmp(line a, line b) {return (a.l<b.l) ? true : false;}

int n, lis;
int dp[101], ddp[101];
line lines[101];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &lines[i].l, &lines[i].r);
    }
    sort(lines+1, lines+n+1, cmp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++)
            if(lines[i].r>lines[j].r)
                dp[i]=max(dp[i],dp[j]+1);
        lis=max(dp[i],lis);
    }
    printf("%d\n", n-lis-1);
}