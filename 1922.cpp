#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node{
    int src, dst, val;
    bool operator<(const node &n) const{
        return val < n.val;
    }
} links[100000];
int parent[1000];

int find(int u){
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c; --a; --b;
        links[i].src = a; links[i].dst = b; links[i].val = c;
    }
    sort(links, links+m);
    memset(parent, -1, sizeof(parent));
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int u = find(links[i].src), v = find(links[i].dst);
        if(u == v) continue;
        parent[u] += parent[v];
        parent[v] = u;
        ans += links[i].val;
    }
    cout << ans;
}