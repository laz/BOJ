#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[1000001];
int n;

void input() {
    fastio;
    cin >> n;
}

int main() {
    input();

    stack<pair<int, int> > stk;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        
        while(!stk.empty() && stk.top().first < num) {
            arr[stk.top().second] = num;
            stk.pop();
        }
        stk.push({num, i});
    }

    while(!stk.empty()) {
        arr[stk.top().second] = -1;
        stk.pop();
    }

    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}