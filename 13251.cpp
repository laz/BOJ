#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[50];
int m, k, sum = 0;

void input() {
    fastio;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> k;
    cout << fixed << setprecision(9);
}

int main() {
    input();

    double ans = 0;
    for(int i = 0; i < m; ++i) {
        if(arr[i] < k) continue;
        double prob = 1;
        for(int j = 0; j < k; ++j) {
            prob *= (double)(arr[i]-j) / (sum-j);
        }
        ans += prob;
    }
    cout << ans;
}