#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr+n);

    int s=0, e=0, ans=2e9+1, dif=0;
    while(1){
        int dif = arr[e] - arr[s];
        if(dif >= m) s++;
        else if(e == n) break;
        else e++;
        if(dif >= m) ans = min(ans, dif);
    }
    cout << ans;
}