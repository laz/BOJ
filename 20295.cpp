#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 17, MAX = 100001;
vector<int> adj[MAX];
int st[N][MAX], candies[N][MAX], depth[MAX], arr[MAX];
bool exist[6];
int n, m;

void input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int c; cin >> c;
        arr[i] = 1 << c;
        exist[c] = true;
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> m;
}

void bfs() {
    queue<pii> q;
    depth[1] = 1;
    q.push({1, 0});
    while(!q.empty()) {
        auto [from, d] = q.front(); q.pop();
        for(auto& to : adj[from]) {
            if(st[0][to] || to == 1) continue;
            st[0][to] = from;
            candies[0][to] |= arr[from];
            depth[to] = d+1;
            q.push({to, d+1});
        }
    }
}

bool lca(int u, int v, int c) {
    
    if(depth[u] < depth[v]) swap(u, v);
    int cand = arr[u] | arr[v];
    int diff = depth[u] - depth[v];
    for(int i = 0; i < N; ++i) {
        if(diff & (1 << i)) {
            cand |= candies[i][u];
            u = st[i][u];
        }
    }
    if(u == v) {
        if(cand & (1 << c)) return true;
        return false;
    }

    for(int i = N-1; i >= 0; --i) {
        if(st[i][u] != st[i][v]) {
            cand |= candies[i][u];
            cand |= candies[i][v];
            u = st[i][u], v = st[i][v];
        }
    }

    cand |= candies[0][u];
    cand |= candies[0][v];
    if(cand & (1 << c)) return true;
    return false;
}

int main() {
    fastio;
    input();

    bfs();

    for(int i = 1; i <= n; ++i) candies[0][i] |= arr[i];
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= n; ++j) {
            st[i][j] = st[i-1][st[i-1][j]];
            candies[i][j] = candies[i-1][j] | candies[i-1][st[i-1][j]];
        }
    }

    m--;
    int ia, ib; cin >> ia >> ib;
    // 처음엔 사탕이 존재하면 play
    if(exist[ib]) cout << "PLAY\n";
    else cout << "CRY\n";
    int from = ia; 

    while(m--) {
        int to, candy; cin >> to >> candy;
        cout << (lca(from, to, candy) ? "PLAY\n" : "CRY\n");
        from = to;
    }
}