#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool adj[401][401];
int n, K, s;

void input() {
    cin >> n >> K;
    for(int i = 0; i < K; ++i) {
        int a, b; cin >> a >> b;
        adj[a][b] = true;
    }
    cin >> s;
}

int main() {
    fastio;
    input();

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(adj[i][k] && adj[k][j]) adj[i][j] = 1;
            }
        }
    }

    while(s--) {
        int a, b; cin >> a >> b;
        if(!adj[a][b] && !adj[b][a]) cout << "0\n";
        else if(adj[a][b]) cout << "-1\n";
        else cout << "1\n";
    }
}