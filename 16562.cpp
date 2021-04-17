#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cost[10000], parent[10000], minCost[10000];

int find(int u){
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return ;

    if(u > v) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> cost[i];
    memset(parent, -1, sizeof(parent));
    memset(minCost, 0x3f, sizeof(minCost));
    
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b; --a; --b; 
        merge(a, b);
    }
    
    vector<bool> list(n, false);
    for(int i = 0; i < n; ++i){
        int f = find(i);
        list[f] = true;
        minCost[f] = min(minCost[f], cost[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(!list[i]) continue;
        ans += minCost[i];
    }

    if(ans <= k) cout << ans;
    else cout << "Oh no";
}