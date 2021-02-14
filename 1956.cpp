#include <iostream>
#include <cstring>
using namespace std;

int adj[400][400];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e, a, b, c;
    cin >> v >> e;
    memset(adj, 0x3f, sizeof(adj));
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c; --a; --b;
        adj[a][b] = c;
    }
    
    for(int k = 0; k < v; ++k)
        for(int i = 0; i < v; ++i)
            for(int j = 0; j < v; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int ans = 1e9;
    for(int i = 0; i < v; ++i)
        ans = min(ans, adj[i][i]);
    
    if(ans == 1e9) cout << -1;
    else cout << ans;
}