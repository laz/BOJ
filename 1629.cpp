#include <bits/stdc++.h>
using namespace std;

int n, modulo;

int dac(int exp){
    if(exp == 1)
        return n % modulo;
    if(exp%2 == 1)
        return 1LL * n * dac(exp-1) % modulo;
    int tmp = dac(exp/2);
    return 1LL * tmp * tmp % modulo;
}

int main(){
    int exp;
    scanf("%d %d %d", &n, &exp, &modulo);
    printf("%d\n", dac(exp));
}