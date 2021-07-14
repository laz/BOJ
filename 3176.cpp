#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 17;
vector<pii> adj[100001];
int parent[N][100001], minDist[N][100001], maxDist[N][100001], depth[100001];
int n, m;

void input() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> m;
}

void bfs() {
    queue<pii> q;
    parent[1][0] = 0;
    q.push({1, 0});
    while(!q.empty()) {
        auto [from, d] = q.front(); q.pop();
        depth[from] = d;
        for(auto& [to, dist] : adj[from]) {
            if(parent[0][to] || to == 1) continue;
            parent[0][to] = from;
            minDist[0][to] = dist;
            maxDist[0][to] = dist;
            q.push({to, d+1});
        }
    }
}

pii query(int u, int v) {
    int mn = 2e9, mx = 0;
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < N; ++i) {
        if(diff & (1 << i)) {
            mn = min(mn, minDist[i][u]);
            mx = max(mx, maxDist[i][u]);
            u = parent[i][u];
        }
    }
    if(u == v) return {mn, mx};

    for(int i = N-1; i >= 0; --i) {
        if(parent[i][u] != parent[i][v]) {
            mn = min({mn, minDist[i][u], minDist[i][v]});
            mx = max({mx, maxDist[i][u], maxDist[i][v]});
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    mn = min({mn, minDist[0][u], minDist[0][v]}); 
    mx = max({mx, maxDist[0][u], maxDist[0][v]});
    return {mn, mx};
}

int main() {
    fastio;
    input();
    memset(minDist, 0x7f, sizeof(minDist));
    bfs();

    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= n; ++j) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            maxDist[i][j] = max(maxDist[i-1][j], maxDist[i-1][parent[i-1][j]]);
            minDist[i][j] = min(minDist[i-1][j], minDist[i-1][parent[i-1][j]]);
        }
    }
    
    while(m--) {
        int u, v; cin >> u >> v;
        pii ret = query(u, v);
        cout << ret.first << " " << ret.second << "\n";
    }
}