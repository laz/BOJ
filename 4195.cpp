#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

int parent[200000];

int find(int u){
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

int merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return parent[u];

    parent[u] += parent[v];
    parent[v] = u;
    return parent[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(parent, -1, sizeof(parent));
        unordered_map<string, int> map;
        string s1, s2; int p1, p2, cnt = 0;
        for(int i = 0; i < n; ++i){
            cin >> s1 >> s2;
            if(map.find(s1) == map.end())
                map[s1] = cnt++;
            if(map.find(s2) == map.end())
                map[s2] = cnt++;
            
            cout << -merge(map[s1], map[s2]) << "\n";
        }
    }
}