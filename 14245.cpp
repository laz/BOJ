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
    cin >> m;
}

void propagate(int i, int s, int e) {
    if(lazy[i]) {
        if(i < N) {
            lazy[i<<1] ^= lazy[i];
            lazy[i<<1|1] ^= lazy[i];
        }
        tree[i] ^= lazy[i];
        lazy[i] = 0;
    }
}

void update(int l, int r, int v, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        lazy[i] = v;
        propagate(i, s, e);
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, v, i<<1, s, m);
    update(l, r, v, i<<1|1, m+1, e);
}

int query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i<<1, s, m) + query(l, r, i<<1|1, m+1, e);
}

int main() {
    input();
    while(m--) {
        int a, b; cin >> a >> b;
        if(a == 1) {
            int c, d; cin >> c >> d;
            update(b, c, d);
        }
        else cout << query(b, b) << "\n";
    }
    
}