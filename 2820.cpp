#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

const int N = 1<<19;
vector<ll> adj[N];
ll tree[N<<1], lazy[N<<1];
int from[N], to[N], tmp[N];
int n, m;

void input() {
    fastio;
    int a, b;
    cin >> n >> m >> a;
    tmp[0] = a;
    for(int i = 1; i < n; ++i) {
        cin >> a >> b;
        tmp[i] = a;
        adj[b-1].push_back(i);
    }
}

int idx = -1;
void dfs(int u) {
    from[u] = ++idx;
    for(auto& v : adj[u]) {
        dfs(v);
    }
    to[u] = idx;
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

void update(int l, int r, int x, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);

    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        
        lazy[i] += x;
        propagate(i, s, e);
        return ;
    }
    int m = (s + e) >> 1;
    update(l ,r, x, i<<1, s, m);
    update(l, r, x, i<<1|1, m+1, e);
}

ll query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    propagate(i, s, e);
    
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i<<1, s, m) + query(l, r, i<<1|1, m+1, e);
}

int main() {
    input();

    dfs(0);
    for(int i = 0; i < n; ++i) {
        tree[from[i]+N] = tmp[i];
    }
    
    while(m--) {
        char op; cin >> op;
        if(op == 'p') {
            int a, b; cin >> a >> b;
            update(from[a-1]+1, to[a-1], b);
        }
        else {
            int a; cin >> a;
            cout << query(from[a-1], from[a-1]) << "\n";
        }
    }
}