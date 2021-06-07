#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool visited[10000];
int src, dst, t;

void input() {
    fastio;
    cin >> t;
}

string bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string> > q;
    visited[src] = true;
    q.push({src, ""});

    while(!q.empty()) {
        auto [n, str] = q.front(); q.pop();
        
        if(n == dst) return str;

        int d = (n * 2) % 10000;
        if(!visited[d]) q.push({d, str+'D'});

        int s = n ? n-1 : 9999;
        if(!visited[s]) q.push({s, str+'S'});

        int l = (n%1000)*10 + (n/1000);
        if(!visited[l]) q.push({l, str+'L'});

        int r = (n/10) + (n%10)*1000;
        if(!visited[r]) q.push({r, str+'R'});

        for(int next : {d, s, l, r}) visited[next] = true;
    }
    return "";
}

int main() {
    input();

    while(t--) {
        cin >> src >> dst;
        cout << bfs() << '\n';
    }
}