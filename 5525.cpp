#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s;
int n, m, ans = 0;

void input() {
    fastio;
    cin >> n >> m >> s;
}

int main() {
    input();

    for(int i = 0; i < m; ++i) {
        if(s[i] == 'O') continue;
        int cnt = 0;
        while(s[i+1] == 'O' && s[i+2] == 'I') {
            cnt++;
            i += 2;
            if(cnt == n) {
                cnt--;
                ans++;
            }
        }
    }
    cout << ans;
}