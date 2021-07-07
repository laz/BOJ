#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int N = 1<<16;
vector<int> years;
int tree[N<<1];
int n, m;

void input() {
    cin >> n;
    years.resize(n);
    for(int i = 0; i < n; ++i) cin >> years[i] >> tree[i+N];
    for(int i = N-1; i; --i) tree[i] = max(tree[i<<1], tree[i<<1|1]);
    cin >> m;
}

int uncompress(int x) {
    return lower_bound(all(years), x) - years.begin();
}

int query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return max(query(l, r, i<<1, s, m), query(l ,r, i<<1|1, m+1, e));
}

int solve(int Y, int X) {
    int y = uncompress(Y), x = uncompress(X);

    bool existY = years[y] == Y;
    bool existX = years[x] == X;

    int z = query(uncompress(Y+1), x-1);
    if(existX && existY && tree[x+N] > tree[y+N]) return 0;
    else if(existX && z >= tree[x+N]) return 0;
    else if(existY && z >= tree[y+N]) return 0;
    else if(existY && existX && x-y == X-Y) return 1;
    return 2;
}

int main() {
    fastio;
    input();

    while(m--) {
        int Y, X; cin >> Y >> X;
        
        int ret = solve(Y, X);
        if(ret == 0) cout << "false\n";
        else if(ret == 1) cout << "true\n";
        else cout << "maybe\n";
    }
}