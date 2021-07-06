#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int N = 1<<19;
vector<pii> arr;
int tree[N<<1];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        arr.push_back({num, i+1});
    }
}

void update(int l, int r, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return ;
    if(l <= s && e <= r) {
        tree[i] = 1;
        return ;
    }
    int m = (s + e) >> 1;
    update(l, r, i<<1, s, m);
    update(l, r, i<<1|1, m+1, e);
    tree[i] = tree[i<<1] + tree[i<<1|1];
}

int query(int l, int r, int i = 1, int s = 0, int e = N-1) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    return query(l, r, i<<1, s, m) + query(l, r, i<<1|1, m+1, e);
}

bool cmp(pii& a, pii& b) {
    return a.second < b.second;
}

int main() {
    fastio;
    input();

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    
    for(int i = 0; i < n; ++i) {
        arr[i].first = i;
    }

    sort(all(arr), cmp);
    
    for(auto& v : arr) {
        cout << v.second - query(0, v.first-1) << "\n";
        update(v.first, v.first);
    }
}