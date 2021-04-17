#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

priority_queue<int> pq;
int arr[100];
int n, k;

void input() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        pq.push(-arr[i]);
    }
}

int main() {
    input();
    int cnt = 0, num;
    while(cnt < k) {
        num = -pq.top(); pq.pop();
        for(int i = 0; i < n; ++i) {
            long long next = 1LL*num * arr[i];
            if(next > __INT_MAX__) break;
            pq.push(-next);
            if(num % arr[i] == 0) break;
        }
        cnt++;
    }

    cout << num;
}