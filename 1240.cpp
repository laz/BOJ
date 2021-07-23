#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pii> adj[1005];
int dist[1005];
int n, m, src, dst;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n-1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void dfs(int from) {
    for(auto [to, d] : adj[from]) {
        if(dist[to] != -1) continue;
        dist[to] = dist[from] + d;
        dfs(to);
    }
}

int main() {
    fastio;
    input();

    while(m--) {
        memset(dist, -1, sizeof(dist));
        cin >> src >> dst;
        dist[src] = 0;
        dfs(src);
        cout << dist[dst] << "\n";
    }

}