#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int MOD = 987654321;
bool visited[1000005];
int n;

void input() {
    cin >> n;
}

int main() {
    fastio;
    input();

    ll ans = 1;
    for(int i = 2; i <= n; ++i) {
        if(visited[i]) continue;
        int mx = 1;
        for(int j = i*2; j <= n; j +=i) {
            visited[j] = true;
            int t = j;
            int cnt = 0;
            while(t % i == 0 && t > 1) {
                t /= i;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        while(mx--) {
            ans = (ans * i) % MOD;
        }
    }
    cout << ans;
}