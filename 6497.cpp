#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<tuple<int, int, int> > adj;
int parent[200000];
int n, m;

void input() {
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj.emplace_back(c, a, b);
    }
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = parent[u]; v = parent[v];
    if(u == v) return ;
    parent[u] = v;
}

int main() {
    fastio;
    
    while(cin >> n >> m) {
        if(!n && !m) return 0;
        adj.clear();
        input();
        for(int i = 0; i < n; ++i) parent[i] = i;
        sort(adj.begin(), adj.end());

        int ans = 0;
        for(auto& [c, u, v] : adj) {
            if(find(u) == find(v)) {
                ans += c;
                continue;
            }
            merge(u, v);
        }
        cout << ans << "\n";
    }
}