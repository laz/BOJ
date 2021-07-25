#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<int> adj[100005];
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

pii bfs(int src) {
    pii ret = {src, 1};

    queue<pii> q;
    visited[src] = true;
    q.push(ret);
    while(!q.empty()) {
        ret = q.front();
        auto [from, d] = q.front(); q.pop();
        for(int to : adj[from]) {
            if(visited[to]) continue;
            visited[to] = true;
            q.push({to, d+1});
        }
    }
    return ret;
}

int main() {
    fastio;
    input();

    // 가장 먼 거리의 노드 쌍 찾기
    pii a = bfs(1);
    memset(visited, false, sizeof(visited));
    pii b = bfs(a.first);
    
    cout << b.second/2;
}