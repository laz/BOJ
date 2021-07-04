#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1<<17;
int tree[N<<1], lazy[N<<1];
int n;

void input() {
    fastio;
    cin >> n;
}

void propagate(int i, int s, int e) {
    if(lazy[i]) {
        if(i < N) {
            lazy[i<<1] += lazy[i];
            lazy[i<<1|1] += lazy[i];
        }
        tree[i] += lazy[i];
        lazy[i] = 0;
    }
}

void update(int l, int r, int k, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        lazy[i] += k;
        propagate(i, s, e);
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, k, i<<1, s, m);
    update(l, r, k, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] + tree[i<<1|1];
}

int bloom(int l, int r) {
    update(l, l, 0);
    update(r, r, 0);

    int ret = tree[l+N] + tree[r+N];
    tree[l+N] = tree[r+N] = 0;
    return ret;
}

int main() {
    input();
    while(n--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << bloom(l, r) << "\n";
        update(l+1, r-1, 1);
    }
}