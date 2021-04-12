#include <iostream>
#include <algorithm>
using namespace std;

int parent[100001];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return ;
    parent[u] = v;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int g, p; cin >> g >> p;
    for(int i = 1; i <= g; ++i) parent[i] = i;

    int ans = 0;
    for(int i = 0; i < p; ++i){
        int a; cin >> a; 
        int u = find(a);
        if(u == 0) break;
        merge(u, u-1);
        ans++;
    }
    cout << ans;
}