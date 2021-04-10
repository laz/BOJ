#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check[1000];

struct uf{
    vector<int> parent;
    uf(int n): parent(n){
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return ;
        parent[u] = v;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin >> n >> m; uf buf(n);
    for(int i = 0; i < m; ++i){
        cin >> u >> v; --u; --v;
        buf.merge(u, v);
    }
    set<int> s;
    for(int i = 0; i < n; ++i)
        s.insert(buf.find(i));
    cout << s.size();
}