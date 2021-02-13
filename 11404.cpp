#include <iostream>
#include <cstring>
using namespace std;

int adj[101][101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    memset(adj, 0x3f, sizeof(adj));
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c; --a; --b;
        adj[a][b] = min(adj[a][b], c);
    }
    for(int i = 0; i < n; ++i)
        adj[i][i] = 0;

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            if(adj[i][k] > 1e9) continue;
            for(int j = 0; j < n; ++j){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(adj[i][j] > 1e9) cout << 0 << " ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}