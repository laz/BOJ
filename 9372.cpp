#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, m, a, b;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) cin >> a >> b;
}

int main() {
    fastio;
    cin >> t;
    
    while(t--) {
        input();
        cout << n-1 << "\n";
    }
}