#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int N = 1<<17;
vector<int> tree[N<<1];
int n, m;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        tree[N+i].push_back(num);
    }
    for(int i = N-1; i; --i) {
        tree[i].reserve(tree[i<<1].size() + tree[i<<1|1].size());
        auto& l = tree[i<<1];
        auto& r = tree[i<<1|1];
        merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(tree[i]));
    }
    cin >> m;
}

int query(int l, int r, int k, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
    int m = (s + e) >> 1;
    return query(l, r, k, i<<1, s, m) + query(l, r, k, i<<1|1, m+1, e);
}

int main() {
    input();
    int last_ans = 0;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        a ^= last_ans, b ^= last_ans, c ^= last_ans;
        last_ans = query(a-1, b-1, c);
        cout << last_ans << "\n";
    }
}