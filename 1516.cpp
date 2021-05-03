#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> adj[501];
int indegree[501], arr[501], cost[501];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        int req;
        while(cin >> req) {
            if(req == -1) break;
            ++indegree[i];
            adj[req].push_back(i);
        }
    }
}

int main() {
    input();

    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(!indegree[i]){
            q.push(i);
            cost[i] = arr[i];
        }
    }
    
    while(!q.empty()) {
        int from = q.front(); q.pop();
        for(int to : adj[from]) {
            --indegree[to];
            cost[to] = max(cost[to], cost[from] + arr[to]);
            if(!indegree[to]) {
                q.push(to);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << cost[i] << "\n";
}