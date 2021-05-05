#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n;

void input() {
    fastio;
    cin >> t;
}

int main() {
    input();
    int num;
    char s;

    while(t--) {
        cin >> n;

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
        priority_queue<pair<int, int> > maxHeap;
        vector<bool> valid(n, true);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            cin >> s >> num;

            if(s == 'I') {
                minHeap.push({num, i});
                maxHeap.push({num, i});
                ++cnt;
            }
            else {
                if(cnt == 0) continue;
                if(num == 1) {
                    while(!maxHeap.empty() && !valid[maxHeap.top().second]) 
                        maxHeap.pop();
                    
                    valid[maxHeap.top().second] = false;
                    maxHeap.pop();
                }
                else {
                    while(!minHeap.empty() && !valid[minHeap.top().second]) 
                        minHeap.pop();
                        
                    valid[minHeap.top().second] = false;
                    minHeap.pop();
                }
                --cnt;
            }
        }

        if(cnt == 0) cout << "EMPTY\n";
        else {
            while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
            while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
            cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
        }
    }
}