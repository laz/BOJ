#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> adj[32001];
int degree[32001];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        ++degree[b];
        adj[a].push_back(b);
    }
}

int main() {
    input();

    priority_queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(degree[i] == 0)
            q.push(-i);
    }

    while(!q.empty()) {
        int from = -q.top(); q.pop();
        cout << from << " ";
        for(int to : adj[from]) {
            if(--degree[to] == 0) {
                q.push(-to);
            }
        }
    }

}