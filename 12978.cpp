#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<int> adj[100005];
int cache[100005][2];
bool visited[100005];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int d(int from, bool built) {
    int& ret = cache[from][built];
    if(ret != -1) return ret;

    visited[from] = true;
    ret = 0;
    for(int to : adj[from]) {
        if(visited[to]) continue;
        visited[to] = true;
        if(built) ret += min(d(to, true)+1, d(to, false));
        else ret += d(to, true)+1;
        visited[to] = false;
    }
    return ret;
}

int main() {
    fastio;
    input();
    memset(cache, -1, sizeof(cache));
    cout << min(d(1, true)+1, d(1, false));
}