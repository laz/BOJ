#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct state {
    int from, dist; bool valid;
    state(int ff, int dd, int vv) {from = ff, dist = dd, valid = vv;}
};

bool visited[501][501];
int adj[501][501];
int n, m, src, dst;

void input() {
    cin >> src >> dst;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = c;
    }
}

void dfs(int from, const vector<vector<int> >& path) {
    for(auto& to : path[from]) {
        if(visited[to][from]) continue;
        visited[to][from] = true;
        adj[to][from] = -1;
        dfs(to, path);
    }
}

int dijkstra() {
    vector<int> dist(n+1, 2e9);
    vector<vector<int> > path(n+1, vector<int>());
    priority_queue<pii> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while(!pq.empty()) {
        auto [from, d] = pq.top(); pq.pop(); d *= -1;
        if(dist[from] < d) continue;
        for(int to = 0; to < n; ++to) {
            int nDist = d + adj[from][to];
            if(adj[from][to] == -1 || dist[to] < nDist) continue;
            if(dist[to] > nDist) {
                path[to].clear();
                dist[to] = nDist;
                pq.push({to, -nDist});
            }
            path[to].push_back(from);
        }
    }
    // remove shortest path
    dfs(dst, path);
    return dist[dst];
}

int main() {
    fastio;
    while(cin >> n >> m) {
        if(!n && !m) break;
        memset(adj, -1, sizeof(adj));
        memset(visited, false, sizeof(visited));
        input();
    
        dijkstra();
        int ret = dijkstra();
        cout << (ret == 2e9 ? -1 : ret) << "\n";
    }
}