#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int t, m;

int main() {
    fastio;
    cin >> t;
    while(t--) {
        cin >> m;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        cout << (m+1)/2 << "\n";

        int cnt = 0;
        for(int i = 1; i <= m; ++i) {
            int n; cin >> n;
            
            if(i & 1) {
                if(maxHeap.empty() || n <= minHeap.top()) maxHeap.push(n);
                else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(n);
                }
                cout << maxHeap.top() << " ";
                if(++cnt % 10 == 0) cout << "\n";
            }
            else {
                if(n >= maxHeap.top()) minHeap.push(n);
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(n);
                }
            }
        }
        cout << "\n";
    }
}