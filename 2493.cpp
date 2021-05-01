#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[500000], ans[500000];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

int main() {
    input();

    stack<pair<int, int> > stk;
    for(int i = n-1; i >= 0; --i) {
        while(!stk.empty() && stk.top().first < arr[i]) {
            ans[stk.top().second] = i+1;
            stk.pop();
        }
        stk.push({arr[i], i});
    }
    
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}