#include <bits/stdc++.h>
using namespace std;

int l1, l2, cnt, lcs;
int dp[1001][1001];
char str1[1001], str2[1001], lcss[1001];

int main(){
    scanf("%s %s", str1, str2);
    l1=strlen(str1);
    l2=strlen(str2);
    for(int i = 1 ; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    lcs=dp[l1][l2];
    cnt=lcs-1;
    while(cnt>=0){
        if(dp[l1][l2]==dp[l1][l2-1])
            l2--;
        else if(dp[l1][l2]==dp[l1-1][l2])
            l1--;
        else{
            lcss[cnt]=str1[l1-1];
            l1--;
            l2--;
            cnt--;
        }
    }
    printf("%d\n%s\n", lcs, lcss);
}