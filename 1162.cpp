#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct state {
    ll from, c, k;
    state(ll ff, ll cc, ll kk) {
        from = ff, c = cc, k = kk;
    }
    bool operator<(const state &s) const {
        return c > s.c;
    }
};

vector<pii> adj[10005];
int n, m, K;

void input() {
    cin >> n >> m >> K;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

int main() {
    fastio;
    input();
    vector<vector<ll>> dist(n+1, vector<ll>(K+1, 2e18));
    priority_queue<state> pq;
    for(int i = 0; i <= K; ++i) dist[1][i] = 0;
    pq.push(state(1, 0, 0));
    while(!pq.empty()) {
        auto [from, c, k] = pq.top(); pq.pop();
        if(dist[from][k] < c) continue;
        for(auto& [to, toCost] : adj[from]) {
            ll nCost = c + toCost;

            if(k < K && c < dist[to][k+1]) {
                dist[to][k+1] = c;
                pq.push(state(to, c, k+1));
            }

            if(nCost >= dist[to][k]) continue;
            dist[to][k] = nCost;
            pq.push(state(to, nCost, k));
        }
    }

    ll ans = 2e18;
    for(int i = 0; i <= K; ++i) {
        ans = min(ans, dist[n][i]);
    }
    cout << ans;
}