#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<int> adj[100001];
bool visited[100001];
int arr[100001], order[100001];
int n;

void input() {
    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        order[arr[i]] = i;
    }
}

bool cmp(int& a, int& b) {
    return order[a] < order[b];
}

int idx = 1;
void d(int i) {
    if(i != arr[idx]) {
        cout << 0;
        exit(0);
    }

    idx++;
    for(auto& v : adj[i]) {
        if(visited[v]) continue;
        visited[v] = true;
        d(v);
    }
}

int main() {
    fastio;
    input();
    
    for(int i = 1; i <= n; ++i) {
        sort(all(adj[i]), cmp);
    }

    visited[1] = true;
    d(1);
    cout << 1;
}