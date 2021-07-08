#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll cache[205][205];
int n, m, k, cnt = 0;

void input() {
    cin >> n >> m >> k;
}

ll binomial(ll a, ll b) {
    if(b == 0 || a == b) return 1;
    ll& ret = cache[a][b];
    if(ret != -1) return ret;
    ll tmp = binomial(a-1, b-1) + binomial(a-1, b);
    return ret = tmp > 1e9 ? 2e9 : tmp;
}

void d(int a, int z, int idx) {
    ll bin = binomial(a+z-1, z);
    if(idx <= bin && a) {
        cout << 'a';
        d(a-1, z, idx);
    }
    else if(z) {
        cout << 'z';
        d(a, z-1, idx - bin);
    }
}

int main() {
    fastio;
    input();
    memset(cache, -1, sizeof(cache));

    if(binomial(n+m, m) < k) {
        cout << -1;
        return 0;
    }
    d(n, m, k);
}