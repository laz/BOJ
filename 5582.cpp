#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int cache[2][4001];
string a, b;

void input() {
    cin >> a >> b;
}

int main() {
    fastio;
    input();

    int ans = 0;
    for(int i = 1; i <= a.size(); ++i) {
        for(int j = 1; j <= b.size(); ++j) {
            if(a[i-1] == b[j-1]) {
                cache[i&1][j] = cache[(i-1)&1][j-1] + 1;
                ans = max(ans, cache[i&1][j]);
            }
            else cache[i&1][j] = 0;
        }
    }
    cout << ans;
}