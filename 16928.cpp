#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool visited[111];
int ladders[111], snakes[111];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        ladders[a] = b;
    }
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        snakes[a] = b;
    }
}

void bfs() {
    queue<pair<int, int> > q;
    q.push({1, 0});
    visited[1] = true;
    while(!q.empty()) {
        auto from = q.front(); q.pop();
        if(from.first == 100) {
            cout << from.second;
            break;
        }
        for(int to : {1, 2, 3, 4, 5, 6}) {
            int next = from.first + to;
            
            if(ladders[next]) 
                next = ladders[next];
            else if(snakes[next]) 
                next = snakes[next];

            if(visited[next] || next > 100) continue;
            visited[next] = true;
            q.push({next, from.second+1});
        }
    }
}

int main() {
    input();
    bfs();
}