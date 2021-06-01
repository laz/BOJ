#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t;

void input() {
    fastio;
    cin >> t;
}

int main() {
    input();

    while(t--) {
        int n; cin >> n;
        string name, type;
        map<string, int> m;
        for(int i = 0; i < n; ++i) {
            cin >> name >> type;
            m[type]++;
        }

        int cnt = 1;
        for(auto it : m) {
            cnt *= it.second+1;
        }
        cout << cnt-1 << '\n';
    }
}