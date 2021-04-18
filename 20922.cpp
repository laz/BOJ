#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[200000], cnt[100001];
int n, k;

void input() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

int main() {
    input();

    int ans = 0;
    for(int e = 0, s = 0; e < n; e++) {
        cnt[arr[e]]++;
        if(cnt[arr[e]] > k) {
            while(arr[s] != arr[e]) 
                cnt[arr[s++]]--;
            cnt[arr[e]]--;
            s++;
        }
        else 
            ans = max(ans, e+1-s);
    }
    cout << ans;
}