#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pair<int, int> > adj[1001];
int n, m, src, dst;

void input() {
    fastio;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    cin >> src >> dst;
}

void dijkstra() {
    vector<int> dist(n+1, 1e9);
    vector<int> path(n+1, 0);

    priority_queue<pair<int, int> > pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [distFrom, from] = pq.top(); pq.pop(); distFrom *= -1;
        if(dist[from] > distFrom) continue;
        
        for(auto [distTo, to] : adj[from]) {
            int nextDist = distFrom + distTo;
            if(nextDist >= dist[to]) continue;
            path[to] = from;
            dist[to] = nextDist;
            pq.push({-nextDist, to});
        }
    }
    cout << dist[dst] << '\n';

    // trace
    int cnt = 0;
    stack<int> trace;
    while(dst != src) {
        trace.push(dst);
        dst = path[dst];
    }
    trace.push(src);

    cout << trace.size() << '\n';
    while(!trace.empty()) {
        cout << trace.top() << ' ';
        trace.pop();
    }
}

int main() {
    input();
    dijkstra();
}