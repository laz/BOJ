#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct state {
    int from, c, d;
    state(int ff, int cc, int dd) {
        from = ff, c = cc, d = dd;
    }
};

vector<state> adj[105];
int t, n, m, k;

void input() {
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].push_back(state(b, c, d));
    }
}

void dijkstra() {
    vector<vector<int> > visited(n+1, vector<int>(10005, 2e9));
    queue<state> q;
    visited[1][0] = 0;
    q.push(state(1, 0, 0));

    while(!q.empty()) {
        auto [from, c, d] = q.front(); q.pop();
        if(d > visited[from][c]) continue;
        for(auto& to : adj[from]) {
            int nDist = d + to.d;
            int nCost = c + to.c;
            if(nCost > m || visited[to.from][nCost] <= nDist) continue;
            visited[to.from][nCost] = nDist;
            q.push(state(to.from, nCost, nDist));
        }
    }

    int ans = 2e9;
    for(auto& v : visited[n]) {
        ans = min(ans, v);
    }
    if(ans == 2e9) cout << "Poor KCM\n";
    else cout << ans << "\n";
}

int main() {
    fastio;
    cin >> t;
    
    while(t--) {
        for(int i = 1; i <= n; ++i) adj[i].clear();
        input();
        dijkstra();
    }
}