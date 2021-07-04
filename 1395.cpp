#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1<<17;
int tree[N<<1], lazy[N<<1];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
}

void propagate(int i, int s, int e) {
    if(lazy[i]) {
        if(i < N) {
            lazy[i<<1] += lazy[i];
            lazy[i<<1|1] += lazy[i];
        }
        if(lazy[i] & 1) tree[i] = (e-s+1) - tree[i];
        lazy[i] = 0;
    }
}

void update(int l, int r, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        lazy[i]++;
        propagate(i, s, e);
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, i<<1, s, m);
    update(l, r, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] + tree[i<<1|1];
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
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) update(b-1, c-1);
        else cout << query(b-1, c-1) << "\n";
    }
}