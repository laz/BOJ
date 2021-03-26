#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] = arr[i-1] + arr[i];
    }

    int ans = -1e9;
    for(int i = 1; i <= n-k+1; ++i)
        ans = max(ans, arr[i+k-1] - arr[i-1]);
    cout << ans;
}