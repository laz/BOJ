#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[1000];
vector<int> dist;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, a, b, c, src, dst;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c; --a; --b;
        adj[a].push_back({c, b});
    }
    cin >> src >> dst; --src; --dst;

    dist = vector<int>(n, 1e9);
    priority_queue<pair<int, int> > pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first, from = pq.top().second; pq.pop();
        if(cost > dist[from]) continue;
        for(auto p : adj[from]){
            int nCost = p.first + cost;
            int to = p.second;
            if(nCost >= dist[to]) continue;
            pq.push({-nCost, to});
            dist[to] = nCost;
        }
    }
    
    cout << dist[dst];
}