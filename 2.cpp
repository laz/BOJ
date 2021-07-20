#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

unordered_map<string, priority_queue<int>> um;
int n;

void input() {
    cin >> n;
}

int main() {
    fastio;
    input();

    ll ans = 0;
    while(n--) {
        int q; string name; cin >> q >> name;
        if(q == 1) {
            int k, num; cin >> k;
            for(int i = 0; i < k; ++i) {
                cin >> num;
                um[name].push(num);
            }
        }
        else {
            int b; cin >> b;
            while(b-- && !um[name].empty()) {
                ans += um[name].top();
                um[name].pop();
            }
        }
    }
    cout << ans;
}