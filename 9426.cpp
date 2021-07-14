#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 1<<16;
ll tree[N<<1];
int arr[250000];
int n, K;

void input() {
    cin >> n >> K;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

ll query(int k, int i = 1, int s = 0, int e = N-1) {
    if(s == e) return s;
    int m = (s + e) >> 1;
    if(k <= tree[i<<1]) return query(k, i<<1, s, m);
    return query(k-tree[i<<1], i<<1|1, m+1, e);
}

void update(int l, int r, int k, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        tree[i] += k;
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, k, i<<1, s, m);
    update(l, r, k, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] + tree[i<<1|1];
}

int main() {
    fastio;
    input();

    int k = (K+1)/2;
    ll ans = 0;
    for(int i = 0; i < K-1; ++i) update(arr[i], arr[i], 1);
    for(int i = K-1; i < n; ++i) {
        update(arr[i], arr[i], 1);
        ans += query(k);
        update(arr[i-K+1], arr[i-K+1], -1);
    }
    cout << ans;
}