#include <iostream>
#include <vector>
using namespace std;

int secret[51], parent[51];
vector<int> parties[51];

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
    int n, m, s; cin >> n >> m >> s; 
    for(int i = 1; i <= s; ++i) cin >> secret[i];
    
    for(int i = 1; i <= n; ++i) parent[i] = i;

    int num, tmp;
    for(int i = 1; i <= m; ++i){
        cin >> num;
        parties[i].reserve(num);
        for(int j = 0; j < num; ++j){
            cin >> tmp;
            parties[i].push_back(tmp);
            if(j >= 1)
                merge(parties[i][j-1], parties[i][j]);
            
        }
        
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        bool able = true;
        for(auto p : parties[i]){
            for(int j = 1; j <= s; ++j){
                if(find(p) == find(secret[j])){
                    able = false;
                    break;
                }
            }
            if(!able) break;
        }
        if(able) ans++;
    }

    cout << ans;
}