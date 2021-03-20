#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<int> adj[500];

int b(int src){
    int nodes = 0, vertices = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int from = q.front(); q.pop();
        nodes++;
        for(int to : adj[from]){
            vertices++;
            if(visited[to]) continue;
            q.push(to);
            visited[to] = true;
        }
    }
    return nodes-1 == vertices/2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v, cnt = 0;
    while(cin >> n >> m){
        if(!n && !m) break;
        cnt++;
        visited = vector<bool>(n, false);
        for(int i = 0; i < n; ++i) adj[i].clear();
        for(int i = 0; i < m; ++i){
            cin >> u >> v; --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int trees = 0;
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            if(b(i)) trees++;
        }
        if(!trees) cout << "Case " << cnt << ": No trees.\n";
        else if(trees == 1) cout << "Case " << cnt << ": There is one tree.\n";
        else cout << "Case " << cnt << ": A forest of " << trees << " trees.\n";
    }
}