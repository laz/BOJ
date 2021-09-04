#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool visited[10005];
vector<int> adj[10005];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
}

int d(int from) {

    int ret = 1;
    visited[from] = true;

    for(int to : adj[from]) {
        if(visited[to]) continue;
        ret += d(to);
    }
    return ret;
}

int main() {
    fastio;
    input();

    priority_queue<pii> pq;
    for(int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        pq.push({d(i), -i});
    }

    int best = pq.top().first;
    while(!pq.empty() && pq.top().first == best) {
        cout << -pq.top().second << ' ';
        pq.pop();
    }

}