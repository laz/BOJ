#include <cstdio>
using namespace std;

const int modulo = 1000000007;
int n, k, inv;
int dp[4000001] = {1, 1, };

int dac(int exp){
    if(exp == 1)
        return inv % modulo;
    if(exp%2 == 1)
        return 1LL * inv * dac(exp-1) % modulo;
    int tmp = dac(exp/2);
    return 1LL * tmp * tmp % modulo;
}

int main(){
    scanf("%d %d", &n, &k);
    if((!k) || (n == k) || (n == 1 && k == 1)){
        printf("%d\n", 1);
        return 0;
    }
    //페르마의 소정리랍니다...
    for(int i = 2; i <= n; ++i)
        dp[i] = 1LL * dp[i-1] * i % modulo;
        
    inv = 1LL * dp[k] * dp[n-k] % modulo;
    inv = dac(modulo - 2);

    int ans = 1LL * dp[n] * inv % modulo;
    printf("%d\n", ans);
}