#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> innode[32001];
bool visited[32001], isNode[32001];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        isNode[a] = true;
        innode[b].push_back(a);
    }
}

void print(int u) {
    if(visited[u]) return;
    visited[u] = true;

    for(int v : innode[u]) 
        print(v);
    
    cout << u << " ";
}

int main() {
    input();

    for(int i = 1; i <= n; ++i) 
        if(!isNode[i]) 
            print(i);
}