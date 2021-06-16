#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int SZ = 1 << 17;
int minTree[SZ << 1], maxTree[SZ << 1];
int t, n, k;

void input() {
    fastio;
    memset(minTree, 0x3f, sizeof(minTree));
    memset(maxTree, 0, sizeof(maxTree));
    cin >> n >> k;
    for(int i = 0; i < n; ++i) minTree[SZ + i] = maxTree[SZ + i] = i;
    
    for(int i = SZ-1; i > 0; --i) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1|1]);
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1|1]);
    }
}

void update(int a, int b) {
    a += SZ; b += SZ;
    swap(minTree[a], minTree[b]);
    swap(maxTree[a], maxTree[b]);
    
    while(a > 1) {
        a >>= 1;
        minTree[a] = min(minTree[a << 1], minTree[a << 1|1]);
        maxTree[a] = max(maxTree[a << 1], maxTree[a << 1|1]);
    }

    while(b > 1) {
        b >>= 1;
        minTree[b] = min(minTree[b << 1], minTree[b << 1|1]);
        maxTree[b] = max(maxTree[b << 1], maxTree[b << 1|1]);
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
    cin >> t;
    while(t--) {
        input();
        for(int i = 0; i < k; ++i) {
            int q, a, b; cin >> q >> a >> b;
            
            if(!q) update(a, b);
            else {
                auto res = query(a, b);
                if(res.first == a && res.second == b) cout << "YES\n";
                else cout << "NO\n";
            } 
        }
    }
}