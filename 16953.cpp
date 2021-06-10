#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

int n, m;

void input() {
    fastio;
    cin >> n >> m;
}

ll bfs() {
    queue<pair<ll, ll> > q;
    q.push({n, 1});
    while(!q.empty()) {
        auto [from, cnt] = q.front(); q.pop();
        if(from == m) return cnt;
        if(from*2 <= m) q.push({from*2, cnt+1});
        if(from*10+1 <= m) q.push({from*10+1, cnt+1});
    }
    return -1;
}

int main() {
    input();

    cout << bfs();
}