#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pair<int, int> arr[1000000];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
}

int main() {
    input();
    sort(arr, arr+n);

    priority_queue<int> pq;
    int from, to, ans = 0;
    for(int i = 0; i < n; ++i){
        pq.push(-arr[i].second);

        int prev = -1;
        while(arr[i].first >= -pq.top()) {
            prev = -pq.top();
            pq.pop();
        }

        if(pq.size() > ans) {
            from = arr[i].first;
            to = -pq.top();
            ans = pq.size();
        } else if(pq.size() == ans && prev == arr[i].first) {
            to = -pq.top();
        }
    }
    cout << ans << "\n";
    cout << from << " " << to;
}