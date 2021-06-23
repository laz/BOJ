#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int tree[1<<22];
int n;

void input() {
    fastio;
    cin >> n;
}

int update(int t, int v, int i = 1, int s = 0, int e = (1<<21)-1) {
    if(t < s || t > e) return tree[i];
    if(s == e) return tree[i] += v;
    int m = (s + e) >> 1;
    return tree[i] = update(t, v, i<<1, s, m) + update(t, v, i<<1|1, m+1, e);
}

int query(int k, int i = 1, int s = 0, int e = (1<<21)-1) {
    if(s == e) return s;
    int m = (s + e) >> 1;
    if(k <= tree[i<<1]) return query(k, i<<1, s, m);
    return query(k-tree[i<<1], i<<1|1, m+1, e);
}

int main() {
    input();
    while(n--) {
        int a, b; cin >> a >> b;
        if(a == 1) {
            update(b-1, 1);
        }
        else {
            int idx = query(b);
            cout << idx+1 << "\n";
            update(idx, -1);
        }
    }
    
}