#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pair<int, int> meetings[100000];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> meetings[i].first >> meetings[i].second;
}

int main() {
    input();
    sort(meetings, meetings+n);

    int cnt = 0, ans = 0;
    priority_queue<int> pq;    
    for(int i = 0; i < n; ++i) {
        cnt++;
        pq.push(-meetings[i].second);
        while(meetings[i].first >= -pq.top()) {
            cnt--;
            pq.pop();
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}