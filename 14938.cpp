#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pair<int, int> > adj[111];
int arr[111], visited[111];
int n, m, r;

void input() {
    fastio;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; ++i) 
        cin >> arr[i];
    for(int i = 0; i < r; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
}

int dijk(int src) {
    int ret = 0;

    memset(visited, 0x3f, sizeof(visited));
    priority_queue<pair<int, int> > pq;
    pq.push({0, src});
    visited[src] = 0;

    while(!pq.empty()) {
        auto [distSum, from] = pq.top(); pq.pop(); distSum *= -1;
        if(visited[from] < distSum) continue;
        ret += arr[from];
        for(auto [dist, to] : adj[from]) {
            if(distSum + dist > m || distSum + dist >= visited[to]) continue;
            visited[to] = distSum + dist;
            pq.push({-(distSum+dist), to});
        }
    }
    return ret;
}

int main() {
    input();

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, dijk(i));
    }
    cout << ans;
}