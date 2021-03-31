#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[101], cache[101][10001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    memset(cache, 63, sizeof(cache));
    for(int i = 1; i <= n; ++i)
        cache[i][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(j >= arr[i]) cache[i][j] = min(cache[i-1][j], cache[i][j-arr[i]] + 1);
            else cache[i][j] = cache[i-1][j];
        }
    }

    cout << (cache[n][k] > 1e9 ? -1 : cache[n][k]);
}