#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
int m;

void input() {
    fastio;
    cin >> m;
}

ll inverse(ll b, int n) {
    ll ret = 1;
    while(n) {
        if(n&1) ret = ret * b % MOD;
        b = b * b % MOD;
        n >>= 1;
    }
    return ret;
}

ll fraction(ll a, ll b) {
    return a * inverse(b, MOD-2) % MOD;
}

int main() {
    input();

    ll ans = 0;
    while(m--) {
        int n, s; cin >> n >> s;
        ans = (ans + fraction(s, n)) % MOD;
    }
    cout << ans;
}