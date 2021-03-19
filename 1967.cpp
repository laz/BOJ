#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[10001];    //vertex distance
int v;

pair<int, int> bfs(int src){
    pair<int, int> ret = {src, 0};
    vector<int> visited(v+1, -1);
    queue<pair<int, int> > q;
    q.push({src, 0});
    visited[src] = 0;
    while(!q.empty()){
        int from = q.front().first, dist = q.front().second;
        q.pop();
        if(dist > ret.second){
            ret.first = from;
            ret.second = dist;
        }
        for(auto v : adj[from]){
            int to = v.first, nDist = dist + v.second;
            if(visited[to] >= 0) continue;
            q.push({to, nDist});
            visited[to] = nDist;
            
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> v;
    for(int i = 0; i < v-1; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    auto p = bfs(1);
    auto pp = bfs(p.first);
    
    cout << pp.second;
}