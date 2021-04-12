#include <iostream>
#include <algorithm>
using namespace std;

int parent[10001];

struct link{
    int a, b, c;
    bool operator<(const link &n) const{
        return c < n.c;
    }
} links[100000];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        links[i].a = a; links[i].b = b; links[i].c = c;
    }
    sort(links, links+m);
    for(int i = 0; i < n; ++i) parent[i] = i;
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int u = find(links[i].a), v = find(links[i].b);
        if(u == v) continue;
        parent[u] = v;
        ans += links[i].c;
    }
    cout << ans;
}