#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int adj[101][101];
int arr[101];
int t, n, m, k;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    cin >> k;
    for(int i = 0; i < k; ++i) cin >> arr[i];
}

int main() {
    fastio;
    cin >> t;
    while(t--) {
        memset(adj, 0x3f, sizeof(adj));
        input();
        for(int i = 1; i <= n; ++i) adj[i][i] = 0;
        
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        int mn = 2e9, ans = -1;
        for(int room = 1; room <= n; ++room) {
            int sum = 0;
            for(int i = 0; i < k; ++i) {
                sum += adj[arr[i]][room];
            }
            if(sum < mn) {
                mn = sum;
                ans = room;
            }
        }
        cout << ans << "\n";
    
    }

}