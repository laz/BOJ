#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[25][3];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> arr[i][j];
        }
    }
}

int d(int idx) {
    if(idx >= n-2) {
        return arr[idx][2];
    }
    return max(d(idx+2) + arr[idx][2], d(idx+3) + arr[idx][2]);
}

int main() {
    input();

    cout << max(d(0), d(1));
}