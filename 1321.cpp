#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1<<19;
int tree[N<<1];
int n, m;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> tree[i+N];
    for(int i = N-1; i; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
    cin >> m;
}

void update(int i, int v) {
    i += N;
    tree[i] += v;
    while(i > 1) {
        i >>= 1;
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}

int query(int k, int i = 1, int s = 0, int e = N-1) {
    if(s == e) return s;
    int m = (s + e) >> 1;
    if(k <= tree[i<<1]) return query(k, i<<1, s, m);
    return query(k-tree[i<<1], i<<1|1, m+1, e);
}

int main() {
    input();
    while(m--) {
        int a, b; cin >> a >> b;
        if(a == 1) {
            int c; cin >> c;
            update(b-1, c);
        }
        else cout << query(b)+1 << "\n";
    }
}