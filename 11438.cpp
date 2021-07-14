#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 17;
vector<int> adj[100001];
int parent[100001][N], depth[100001];
int n, m;

void input() {
    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> m;
}

void dfs(int u) {
    for(auto& v : adj[u]) {
        if(depth[v]) continue;
        parent[v][0] = u;
        depth[v] = depth[u]+1;
        dfs(v);
    }
}

int lca(int u, int v) {
    // u deeper than v
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < N; ++i) {
        if(diff & (1 << i)) 
            u = parent[u][i];
    }
    if(u == v) return u;

    for(int i = N-1; i >= 0; --i) {
        if(parent[u][i] != parent[v][i]) 
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}

int main() {
    fastio;
    input();

    depth[1] = 1;
    dfs(1);

    for(int j = 1; j < N; ++j) {
        for(int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    
    while(m--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}