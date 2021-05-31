#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pair<int, int> > adj[1001];
vector<pair<int, int> > rev[1001];
int arr[1001], dist[1001];
int n, m, x;

void input() {
    fastio;
    cin >> n >> m >> x;
    int a, b, c;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        rev[b].push_back({c, a});
    }
}

void dijkstra(vector<pair<int, int> >(&graph)[1001]) {
    memset(dist, 0x3f, sizeof(dist));
    dist[x] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, x});
    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if(-top.first > dist[top.second]) continue;
        for(auto to : graph[top.second]) {
            int nDist = -top.first + to.first;
            if(nDist >= dist[to.second]) continue;
            dist[to.second] = nDist;
            pq.push({-nDist, to.second});
        }
    }
    for(int i = 1; i <= n; ++i) arr[i] += dist[i];
}

int main() {
    input();

    dijkstra(adj);
    dijkstra(rev);

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, arr[i]);
    }  
    cout << ans;
}