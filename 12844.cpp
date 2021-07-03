#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1<<19;
int tree[N<<1], lazy[N<<1];
int n, m;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> tree[i+N];
    for(int i = N-1; i; --i) tree[i] = tree[i<<1] ^ tree[i<<1|1];
    cin >> m;
}

void propagate(int i, int s, int e) {
    if(lazy[i]) {
        if(i < N) {
            lazy[i<<1] ^= lazy[i];
            lazy[i<<1|1] ^= lazy[i];
        }
        tree[i] ^= lazy[i] * ((e-s+1)%2);
        lazy[i] = 0;
    }
}

void update(int l, int r, int k, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        lazy[i] ^= k;
        propagate(i, s, e);
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, k, i<<1, s, m);
    update(l, r, k, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] ^ tree[i<<1|1];
}

int query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i<<1, s, m) ^ query(l, r, i<<1|1, m+1, e);
}

int main() {
    input();
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(b > c) swap(b, c);
        if(a == 1) {
            int d; cin >> d;
            update(b, c, d);
        }
        else cout << query(b, c) << "\n";
    }
}