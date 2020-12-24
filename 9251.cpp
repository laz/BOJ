#include <bits/stdc++.h>
using namespace std;

int l1, l2;
int dp[2][1001];
char str1[1001], str2[1001];

int main(){
    scanf("%s %s", str1, str2);
    l1=strlen(str1);
    l2=strlen(str2);
    for(int i = 1 ; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(str1[i-1]==str2[j-1])
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            else
                dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
        }
    }
    printf("%d\n", max(dp[0][l2], dp[1][l2]));
}