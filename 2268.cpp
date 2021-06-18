#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

int arr[1000007];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
}

ll query(vector<ll>& tree, int l, int r, int i = 1, int s = 0, int e = n-1) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(tree, l, r, i<<1, s, m) + query(tree, l, r, i<<1|1, m+1, e);
}

ll update(vector<ll>& tree, int t, int v, int i = 1, int s = 0, int e = n-1) {
    if(t < s || t > e) return tree[i];
    if(s == e) return tree[i] = v;
    int m = (s + e) >> 1;
    return tree[i] = update(tree, t, v, i<<1, s, m) + update(tree, t, v, i<<1|1, m+1, e);
}

int main() {
    input();
    int h = (int)ceil(log2(n));
    vector<ll> tree((1 << (h+1)));
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(a) update(tree, b-1, c);
        else {
            if(b > c) swap(b, c);
            cout << query(tree, b-1, c-1) << '\n';
        }
    }
}