#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 19;
int st[N][200001];
int n, m;

void input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> st[0][i];
    cin >> m;
}

int main() {
    fastio;
    input();

    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= 200000; ++j) {
            st[i][j] = st[i-1][st[i-1][j]];
        }
    }

    while(m--) {
        int a, b; cin >> a >> b;
        for(int i = 0; i < N; ++i) {
            if(a & (1 << i)) b = st[i][b];
        }
        cout << b << "\n";
    }
}