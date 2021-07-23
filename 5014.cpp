#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool visited[1000005];
int f, s, g, u, d;

void input() {
    cin >> f >> s >> g >> u >> d;
}

int main() {
    fastio;
    input();

    queue<pii> q;
    visited[s] = 0;
    q.push({s, 0});
    while(!q.empty()) {
        auto [from, cnt] = q.front(); q.pop();
        if(from == g) {
            cout << cnt;
            return 0;
        }
        int up = from + u, down = from - d;
        if(up <= f && !visited[up]) {
            visited[up] = true;
            q.push({up, cnt+1});
        }
        if(down >= 1 && !visited[down]) {
            visited[down] = true;
            q.push({down, cnt+1});
        }
    }
    cout << "use the stairs";
}