#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pii> adj[1001];
priority_queue<int> dist[1001];
int n, m, K;

void input() {
    cin >> n >> m >> K;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
}

void dijkstra() {
    priority_queue<pii> pq;
    dist[1].push(0);
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [d, from] = pq.top(); pq.pop(); d *= -1;
        for(auto& [to, toDist] : adj[from]) {
            int nDist = d + toDist;
            if(dist[to].size() < K) {
                dist[to].push(nDist);
                pq.push({-nDist, to});
            }
            else if(dist[to].top() > nDist) {
                dist[to].pop();
                dist[to].push(nDist);
                pq.push({-nDist, to});
            }
        }
    }
}

int main() {
    fastio;
    input();

    dijkstra();
    for(int i = 1; i <= n; ++i) {
        if(dist[i].size() < K) cout << "-1\n";
        else cout << dist[i].top() << "\n";
    }
}