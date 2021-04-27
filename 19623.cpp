#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct meeting{
    int from, to, val;
} meetings[100000];

bool cmp(const meeting& a, const meeting& b) {
    return a.from < b.from;
}

int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> meetings[i].from >> meetings[i].to >> meetings[i].val;
    }
}
int main() {
    input();
    sort(meetings, meetings+n, cmp);

    priority_queue<pair<int, int> > pq;

    int prev = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        // 현재 미팅의 시작시간 전에 끝나는 미팅 중 가장 많은 인원을 수용할 수 있는 값
        while(!pq.empty() && -pq.top().first < meetings[i].from) {
            prev = max(prev, pq.top().second);
            pq.pop();
        }
        int next = meetings[i].val + prev;
        pq.push({-meetings[i].to, next});
        ans = max(ans, next);
    }
    cout << ans;
}