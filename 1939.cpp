#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int> > adj[10000];
int dist[10000];

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push({2e9, start});
    while(!pq.empty()){
        int d = pq.top().first, from = pq.top().second; pq.pop();
        if(dist[from] > d) continue;
        for(auto p : adj[from]){
            int nextDist = min(d, p.first);
            int to = p.second;
            if(dist[to] >= nextDist) continue;
            dist[to] = nextDist;
            pq.push({nextDist, to});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c, src, dst;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c; a--; b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> src >> dst;

    dijkstra(src-1);
    cout << dist[dst-1] << endl;

}