#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool arr[1001];
int n, k;

void input() {
    fastio;
    cin >> n >> k;
}

int main() {
    input();

    int ans = 0;
    for(int i = 2; i <= n; ++i) {
        if(arr[i]) continue;

        for(int j = i; j <= n; j += i) {
            if(arr[j]) continue;
            
            arr[j] = true;
            ++ans;
            if(ans == k) {
                cout << j;
                return 0;
            }
        }
    }
}