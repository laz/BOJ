#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 1<<19;
ll tree[N<<1];
vector<pii> arr;
int idx[1000001];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        idx[a] = i+1;
    }
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        arr.push_back({idx[a], i+1});
    }
}

ll query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i<<1, s, m) + query(l, r, i<<1|1, m+1, e);
}

void update(int l, int r, int k, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        tree[i]++;
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, k, i<<1, s, m), update(l, r, k, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] + tree[i<<1|1];
}

int main() {
    fastio;
    input();

    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += query(arr[i].second, n);
        update(arr[i].second, arr[i].second, 1);
    }
    cout << ans;
}