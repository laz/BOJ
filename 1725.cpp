#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

vector<int> tree;
int arr[100007];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

int init(int i = 1, int s = 0, int e = n-1) {
    if(s == e) return tree[i] = s;
    int m = (s + e) >> 1;
    int left = init(i<<1, s, m);
    int right = init(i<<1|1, m+1, e);
    return tree[i] = arr[left] > arr[right] ? right : left;
}

int query(int l, int r, int i = 1, int s = 0, int e = n-1) {
    if(l > e || r < s) return 2e9;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    int left = query(l, r, i<<1, s, m);
    int right = query(l, r, i<<1|1, m+1, e);
    if(left == 2e9) return right;
    else if(right == 2e9) return left;
    return arr[left] > arr[right] ? right : left;
}

ll solve(int s = 0, int e = n-1) {
    int idx = query(s, e);
    ll area = 1LL * (e - s + 1) * arr[idx];

    if(s < idx) area = max(area, solve(s, idx-1));
    if(e > idx) area = max(area, solve(idx+1, e));
    return area;
}

int main() {
    input();
    int h = (int)ceil(log2(n));
    tree.resize((1 << (h+1)));
    init();
    cout << solve(0, n-1);
}

