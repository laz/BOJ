#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    long long fibs[91];
    int n;
    scanf("%d", &n);

    fibs[0] = 0;
    fibs[1] = 1;
    for(int i = 2 ; i <= n; i++){
        fibs[i] = fibs[i-2] + fibs[i-1];
    }
    printf("%lld\n", fibs[n]);
}