#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool adj[501][501];
int rnk[501], ind[501];
int t, n, m;

void input() {
    memset(adj, false, sizeof(adj));
    memset(ind, 0, sizeof(ind));

    int u; cin >> n;
    for(int i = 1; i <= n; ++i) 
        cin >> rnk[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            adj[rnk[i]][rnk[j]] = true;
            ind[rnk[j]]++;
        }
    }
    cin >> m;
}

int main() {
    fastio;
    cin >> t;

    while(t--) {
        input();
        int u, v;
        for(int i = 1; i <= m; ++i) {
            cin >> u >> v;
            if(adj[u][v]) {
                adj[u][v] = false;
                adj[v][u] = true;
                ind[u]++;
                ind[v]--;
            }
            else {
                adj[v][u] = false;
                adj[u][v] = true;
                ind[v]++;
                ind[u]--;
            }
        }

        // find root
        int root;
        for(int i = 1; i <= n; ++i) {
            if(ind[i] == 0) {
                root = i;
                break;
            }
        }

        queue<int> order;
        queue<int> q;
        q.push(root);

        while(!q.empty()) {
            int from = q.front(); q.pop();
            order.push(from);
            for(int i = 1; i <= n; ++i) {
                if(adj[from][i]) {
                    if(--ind[i] == 0)
                        q.push(i);
                }
            }
        }

        if(order.size() == n) {
            while(!order.empty()) {
                cout << order.front() << " ";
                order.pop();
            }
            cout << "\n";
        } 
        else cout << "IMPOSSIBLE\n";
    }
}