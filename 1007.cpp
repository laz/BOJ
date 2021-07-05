#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using pii = pair<double, double>;

bool visited[22];
vector<pii> v;
double ans;
int t, n;

void input() {
    fastio;
    cout << fixed;
    cout.precision(6);
    cin >> t;
}

void d(int idx, int cnt) {
    if(cnt == n/2) {
        pii p = {0, 0};
        for(int i = 0; i < n; ++i) {
            if(visited[i]) {
                p.first += v[i].first;
                p.second += v[i].second;
            }
            else {
                p.first -= v[i].first;
                p.second -= v[i].second;
            }
        }
        ans = min(ans, sqrt(p.first*p.first + p.second*p.second));
        return ;
    }

    for(int i = idx; i < n; ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        d(i+1, cnt+1);
        visited[i] = false;
    }
}

int main() {
    input();
    while(t--) {
        memset(visited, false, sizeof(visited));
        ans = 2e9;
        v.clear();
        cin >> n;
        for(int i = 0; i < n; ++i) {
            pii p; cin >> p.first >> p.second;
            v.push_back(p);
        }
        d(0, 0);
        cout << ans << "\n";
    }
}