#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int arr[100005];
int n, x;

void input() {
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

bool simulate(int lines) {
    priority_queue<int> pq;
    for(int i = 0; i < lines; ++i) pq.push(0);

    for(int i = 0; i < n; ++i) {
        int top = -pq.top(); pq.pop();
        top += arr[i];
        pq.push(-top);
    }

    int ret = 2e9;
    while(!pq.empty()) {
        ret = -pq.top(); pq.pop();
    }
    if(ret <= x) return true;
    else return false;
}

int main() {
    fastio;
    input();

    int s = 1, e = 100000;
    while(s < e) {
        int m = (s + e) >> 1;
        if(simulate(m)) e = m;
        else s = m+1;
    }
    cout << s;
}