#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int dist[100];

int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1e9, c1, c2;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){

            memset(dist, -1, sizeof(dist));
            //bfs
            queue<int> q;
            dist[i] = dist[j] = 0;
            q.push(i); q.push(j);
            while(!q.empty()){
                int from = q.front(); q.pop();
                for(int v : adj[from]){
                    if(dist[v] != -1) continue;
                    dist[v] = dist[from] + 1;
                    q.push(v);
                }
            }
            
            int sum = 0;
            for(int k = 0; k < n; ++k) sum += dist[k];
            if(ans > sum){
                c1 = i; c2 = j; ans = sum;
            }
        }
    }

    cout << c1+1 << " " << c2+1 << " " << ans*2;
}