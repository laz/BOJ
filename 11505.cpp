#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

const int SZ = 1 << 20, MOD = 1e9+7;
ll tree[SZ << 1];
int n, m, k;

void input() {
    fastio;
    cin >> n >> m >> k; 
    for(int i = 0; i < n; ++i) cin >> tree[SZ + i];
    for(int i = SZ-1; i > 0; --i) tree[i] = tree[i << 1] * tree[i << 1|1] % MOD;
}

void update(int i, int val) {
    i += SZ;
    tree[i] = val;
    while(i > 1) {
        i >>= 1;
        tree[i] = tree[i << 1] * tree[i << 1|1] % MOD;
    }
}

ll query(int l, int r, int i = 1, int s = 0, int e = SZ-1) {
    if(l > e || r < s) return 1;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i << 1, s, m) * query(l, r, i << 1|1, m+1, e) % MOD;
}

int main() {
    input();
    m += k;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(b-1, c);
        else cout << query(b-1, c-1) << '\n';
    }
}