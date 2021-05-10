#include <iostream>
#include <numeric>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;

string num[16];
int len[16], dModK[51], numModK[16];
ll cache[101][1<<15];
int n, MOD, done;

ll PSW(int prev, int visited){
    if(visited == done) return !prev;

    ll& ret = cache[prev][visited];
    if(ret != -1) return ret;

    ret = 0;
    for(int to = 0; to < n; ++to){
        if(visited & (1 << to)) continue;
        int next = ((prev * dModK[len[to]]) + numModK[to]) % MOD;
        ret += PSW(next, visited | (1 << to));
    }
    return ret;
}

int main(){
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> num[i];
    cin >> MOD;

    done = (1 << n) - 1;

    for(int i = 0; i < n; ++i){
        len[i] = num[i].size();
        //각 수 % MOD 
        numModK[i] = (num[i][0] - '0') % MOD;
        for(int j = 1; j < len[i]; ++j)
            numModK[i] = (numModK[i] * 10 + num[i][j] - '0') % MOD;
    }

    //1 ~ 10^50 % MOD
    dModK[0] = 1;
    for(int i = 1; i <= 50; ++i)
        dModK[i] = (dModK[i-1] * 10) % MOD;
    
    memset(cache, -1, sizeof(cache));
    ll ans = PSW(0, 0), q = 1;
    for(int i = 2; i <= n; ++i)
        q *= i;
    ll ggccdd = gcd(ans, q);
    cout << ans/ggccdd << "/" << q/ggccdd << endl;  
}