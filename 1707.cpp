#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int v, e, x, y;
        cin >> v >> e;
        vector<vector<int> > adj;
        for(int i = 0; i < v; ++i)
            adj.push_back(vector<int>());
        for(int i = 0; i < e; ++i){
            cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool bipartite = true;
        int color[v];
        
        memset(color, -1, sizeof(color));
        
        queue<pair<int, bool> > q;
        for(int j = 0; j < v; ++j){
            if(color[j] != -1 || !bipartite) continue;
            color[j] = true;
            q.push({j, true});
            while(!q.empty() && bipartite){
                auto curr = q.front(); q.pop();
                int sz = adj[curr.first].size();
                for(int i = 0; i < sz; ++i){
                    if(curr.second == color[adj[curr.first][i]]){
                        bipartite = false;
                        break;
                    }
                    if(color[adj[curr.first][i]] != -1) continue;
                    color[adj[curr.first][i]] = !curr.second;
                    q.push({adj[curr.first][i], !curr.second});
                }
            }
        }
        if(bipartite) cout << "YES\n";
        else cout << "NO\n";
        
    }
}