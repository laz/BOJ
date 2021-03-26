#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][500001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, h, tmp;
    cin >> n >> h;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        arr[i%2][tmp]++;
    }

    for(int i = h-1; i > 0; --i){
        arr[1][i] = arr[1][i+1] + arr[1][i];
        arr[0][i] = arr[0][i+1] + arr[0][i];
    }

    int mn = 1e9;
    for(int i = 1, j = h; i <= h; ++i, --j){
        arr[1][i] = arr[1][i] + arr[0][j];
        mn = min(mn, arr[1][i]);
    }
    int cnt = 0;
    for(int i = 1; i <= h; ++i)
        if(arr[1][i] == mn) cnt++;
    
    cout << mn << " " << cnt;
}