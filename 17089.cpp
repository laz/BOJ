#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool arr[4004][4004];
int friends[4004];
int n, m, ans = 2e9;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
        friends[a]++;
        friends[b]++;
    }
}

int main() {
    input();
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(!arr[i][j]) continue;
            for(int k = j+1; k <= n; ++k) {
                if(arr[j][k] && arr[i][k]) {
                    int sum = friends[i] + friends[j] + friends[k] - 6;
                    ans = min(ans, sum);
                }
            }
        }
    }
    if(ans == 2e9) cout << -1;
    else cout << ans;
}