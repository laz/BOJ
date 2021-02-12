#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

vector<pair<int, int> > adj[501];
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c; --a; --b;
        adj[a].push_back({b, c});
    }

    vector<long long> upper(n, INF);
    upper[0] = 0;
    for(int i = 0; i < n-1; ++i){
        for(int from = 0; from < n; ++from){
            if(upper[from] == INF) continue;
            for(auto p : adj[from]){
                int to = p.first, dist = p.second;
                if(upper[to] > upper[from] + dist){
                    upper[to] = upper[from] + dist;
                }
            }
        }
    }

    for(int from = 0; from < n; ++from){
        if(upper[from] == INF) continue;
        for(auto p : adj[from]){
            int to = p.first, dist = p.second;
            if(upper[to] > upper[from] + dist){
                cout << -1;
                return 0;
            }
        }
    }

    for(int i = 1; i < n; ++i){
        if(upper[i] == INF) cout << -1 << "\n";
        else cout << upper[i] << "\n";
    }
}