#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool visited[9];
int arr[9];
int sum = 0;

void input() {
    fastio;
    for(int i = 0; i < 9; ++i) cin >> arr[i];
}

void d(int idx, int cnt) {
    if(cnt == 7) {
        if(sum == 100) {
            for(int i = 0; i < 9; ++i)
                if(visited[i]) cout << arr[i] << "\n";
            exit(0);
        }

        return ;
    }
    for(int i = idx; i < 9; ++i) {
        visited[i] = true; sum += arr[i];
        d(i+1, cnt+1);
        visited[i] = false; sum -= arr[i];
    }
}

int main() {
    input();
    sort(arr, arr+9);
    d(0, 0);
}