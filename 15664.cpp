#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool visited[8];
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
        if(prev == arr[i] || visited[i]) continue;
        prev = arr[i];
        save[cnt] = arr[i];
        visited[i] = true;
        d(i+1, cnt+1);
        visited[i] = false;
    }
}

int main() {
    input();
    sort(arr, arr+n);
    d(0, 0);
}