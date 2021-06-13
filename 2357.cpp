#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int SZ = 1 << 17;
int minTree[SZ << 1], maxTree[SZ << 1];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        minTree[SZ + i] = maxTree[SZ + i] = num;
    }

    for(int i = SZ-1; i > 0; --i) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1|1]);
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1|1]);
    }
}

pair<int, int> query(int l, int r, int i = 1, int s = 0, int e = SZ-1) {
    if(l > e || r < s) return {2e9, 0};
    if(l <= s && e <= r) return {minTree[i], maxTree[i]};
    int m = (s + e) >> 1;
    auto q1 = query(l, r, i << 1, s, m), q2 = query(l, r, i << 1|1, m+1, e);
    return {min(q1.first, q2.first), max(q1.second, q2.second)};
}

int main() {
    memset(minTree, 0x3f, sizeof(minTree));
    input();
    while(m--) {
        int a, b; cin >> a >> b;
        auto q = query(a-1, b-1);
        cout << q.first << ' ' << q.second << '\n';
    }
}