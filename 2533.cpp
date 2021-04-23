#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> adj[1000001];
bool visited[1000001];
int cache[1000001][2];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int d(int root, bool earlyAdapter) {
    int& ret = cache[root][earlyAdapter];
    if(ret != -1) return ret;

    ret = 0;
    for(int child : adj[root]) {
        if(visited[child]) continue;
        visited[child] = true;
        if(earlyAdapter) ret += min(d(child, true), d(child, false));
        else ret += d(child, true);
        visited[child] = false;
    }

    if(earlyAdapter) return ret = ret+1;
    else return ret;
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));
    visited[1] = true;
    cout << min(d(1, false), d(1, true));
}