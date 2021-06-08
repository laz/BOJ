#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int adj[101][101];
int via[101][101];

void reconstruct(int u, int v, vector<int>& path){
    if(via[u][v] == -1){
        path.push_back(u);
        path.push_back(v);
    }
    else{
        int k = via[u][v];
        reconstruct(u, k, path);
        path.pop_back();
        reconstruct(k, v, path);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    memset(adj, 0x3f, sizeof(adj));
    memset(via, -1, sizeof(via));
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    
    for(int i = 1; i <= n; ++i)
        adj[i][i] = 0;
    
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << (adj[i][j] > 1e9 ? 0 : adj[i][j]) << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j || adj[i][j] > 1e9)
                cout << "0\n";
            else{
                vector<int> path;
                reconstruct(i, j, path);
                cout << path.size() << " ";
                for(auto p : path)
                    cout << p << " ";
                cout << "\n";
            }
        }
    }
}