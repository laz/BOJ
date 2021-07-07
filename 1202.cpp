#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

pii arr[300005];
int bags[300005];
int n, k;

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    for(int i = 0; i < k; ++i) cin >> bags[i];
}

int main() {
    fastio;
    input();

    sort(arr, arr+n);
    sort(bags, bags+k);

    priority_queue<int> pq;
    ll ans = 0;
    for(int i = 0, idx = 0; i < k; ++i) {
        while(idx < n && arr[idx].first <= bags[i]) {
            pq.push(arr[idx++].second);
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}