#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, m, x, y;

void input() {
    fastio;
}

int main() {
    input();
    cin >> t;
    while(t--) {
        cin >> n >> m >> x >> y;
        bool found = false;
        for(int i = x; i <= n*m; i += n) {
            int rm = i % m == 0 ? m : i % m;
            if(rm == y) {
                cout << i << "\n";
                found = true;
                break;
            }
        }
        if(!found) cout << -1 << "\n";
    }
}