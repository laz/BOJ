#include <iostream>
using namespace std;

int parent[500000];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return true;
    parent[u] = v;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b; cin >> n >> m;
    for(int i = 0; i < n; ++i) parent[i] = i;

    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << i+1;
            return 0;
        }
        merge(a, b);
    }
    cout << 0;
}