#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[7], save[7];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

void d(int idx){
    if(idx == m) {
        for(int i = 0; i < m; ++i) cout << save[i] << " "; cout << "\n";
        return ;
    }
    for(int i = 0; i < n; ++i){
        save[idx] = arr[i];
        d(idx+1);
    }
}

int main(){
    input();
    sort(arr, arr+n);
    d(0);
}

