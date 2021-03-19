#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[100001];    //vertex distance
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
    int num, a, b;
    cin >> v;
    for(int i = 0; i < v; ++i){
        cin >> num;
        while(cin >> a && a != -1){
            cin >> b;
            adj[num].push_back({a, b});
        }
    }
    
    auto p = bfs(1);
    auto pp = bfs(p.first);
    
    cout << pp.second;
}