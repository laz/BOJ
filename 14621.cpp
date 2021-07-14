#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<tuple<int, int, int> > adj;
int parent[1001];
bool isMale[1001];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        char c; cin >> c;
        isMale[i] = c == 'M' ? true : false;
    }
    for(int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if((isMale[a] && isMale[b]) || (!isMale[a] && !isMale[b])) continue;
        adj.emplace_back(c, a, b);
    }
}

int find(int u) {
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return false;
    if(parent[u] > parent[v]) swap(u, v); 
    parent[u] += parent[v];
    parent[v] = u;
    return true;
}

int main() {
    fastio;
    input();
    memset(parent, -1, sizeof(parent));
    sort(adj.begin(), adj.end());
    int ans = 0;
    for(auto& [c, u, v] : adj) {
        if(merge(u, v)) ans += c;
    }
    if(parent[find(1)] == -n) cout << ans;
    else cout << -1;
}