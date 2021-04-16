#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[8], save[8];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

void d(int idx, int cnt){
    if(cnt == m) {
        for(int i = 0; i < m; ++i) cout << save[i] << " "; cout << "\n";
        return ;
    }

    int prev = -1;
    for(int i = idx; i < n; ++i) {
        if(prev == arr[i]) continue;
        prev = arr[i];
        save[cnt] = arr[i];
        d(i, cnt+1);
    }
}

int main() {
    input();
    sort(arr, arr+n);
    d(0, 0);
}