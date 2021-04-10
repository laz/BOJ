#include <iostream>
#include <cstring>
using namespace std;

int parent[1000001];

int find(int u){
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    
    if(parent[u] > parent[v]) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c; cin >> n >> m;
    memset(parent, -1, sizeof(parent));
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        if(!a) merge(b, c);
        else{
            if(find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    for(int i = 0; i <= n; ++i) cout << parent[i] << " ";
}