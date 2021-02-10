#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
vector<vector<pair<int, int> > > adj;
vector<int> dist;

void dijkstra(int start){
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int ,int> > > q;
    dist[start] = 0;
    q.push({0, start});
    while(!q.empty()){
        int cost = q.top().first;
        int from = q.top().second;
        q.pop();
        if(dist[from] < cost) continue;
        int sz = adj[from].size();
        for(int to = 0; to < sz; ++to){
            int there = adj[from][to].second;
            int nextDist = cost + adj[from][to].first;
            if(dist[there] <= nextDist) continue;
            dist[there] = nextDist;
            q.push({nextDist, there});
        }

    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e, k, x, y, w;
    cin >> v >> e >> k;
    dist = vector<int>(v, INF);
    for(int i = 0; i < v; ++i)
        adj.push_back(vector<pair<int, int> >());
    for(int i = 0; i < e; ++i){
        cin >> x >> y >> w;
        adj[x-1].push_back({w, y-1});
    }
    dijkstra(k-1);
    for(int i = 0; i < v; ++i){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}