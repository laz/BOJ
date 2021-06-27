#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

const int N = 1<<17;
ll tree[N<<1];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> tree[i+N];
    for(int i = N-1; i; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
}

void update(int i, int v) {
    for(tree[i += N] = v; i > 1; i >>= 1) tree[i>>1] = tree[i] + tree[i^1];
}

ll query(int l, int r) {
    ll ret = 0;
    for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) ret += tree[l++];
        if(r & 1) ret += tree[--r];
    }
    return ret;
}

int main() {
    input();
    while(m--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        cout << (x > y ? query(y-1, x-1) : query(x-1, y-1)) << "\n";
        update(a-1, b);
    }
}