#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int buildTime[1000], cache[1000];
vector<int> adj[1000];
vector<int> innode[1000];

int build(int target){
    

    int& ret = cache[target];
    if(ret != -1) return ret;

    if(innode[target].empty()) return ret = buildTime[target];
    
    ret = 0;
    for(int n : innode[target])
        ret = max(ret, build(n));
    
    return ret = ret + buildTime[target];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, u, v, w;
        cin >> n >> k;
        memset(cache, -1, sizeof(cache));
        for(int i = 0; i < n; ++i){
            adj[i].clear();
            innode[i].clear();
        }

        for(int i = 0; i < n; ++i)
            cin >> buildTime[i];
        for(int i = 0; i < k; ++i){
            cin >> u >> v; --u; --v;
            adj[u].push_back(v);
            innode[v].push_back(u);
        }
        cin >> w; --w;
        cout << build(w) << "\n";
    }
}