#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
int t, n;

void input() {
    fastio;
    cin >> t;
}

int main() {
    input();
    ll num;
    char s;

    while(t--) {
        cin >> n;

        priority_queue<pair<ll, int> > minHeap, maxHeap;
        vector<bool> valid(n, true);

        for(int i = 0; i < n; ++i) {
            cin >> s >> num;

            if(s == 'I') {
                minHeap.push({-num, i});
                maxHeap.push({num, i});
            }
            else {
                if(num == 1) {
                    while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
                    if(maxHeap.empty()) continue;
                    valid[maxHeap.top().second] = false;
                    maxHeap.pop();
                }
                else {
                    while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
                    if(minHeap.empty()) continue;
                    valid[minHeap.top().second] = false;
                    minHeap.pop();
                }
            }
        }

        while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
        while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();

        if(minHeap.empty()) cout << "EMPTY\n";
        else cout << maxHeap.top().first << " " << -minHeap.top().first << "\n";
    }
}