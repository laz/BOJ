#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[8], save[8];
int n, m;

void d(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; ++i) cout << save[i] << " "; cout << endl;
        return ;
    }

    for(int i = idx; i < n; ++i){
        save[cnt] = arr[i];
        d(i+1, cnt+1);
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);

    d(0, 0);
}