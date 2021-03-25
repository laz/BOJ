#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000], cache[2][100000];
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int ans;
    ans = cache[0][0] = arr[0];
    cache[1][0] = 0;
    for(int i = 1; i < n; ++i){
        cache[0][i] = max(cache[0][i-1], 0) + arr[i];
        cache[1][i] = max(cache[0][i-1], cache[1][i-1] + arr[i]);
        ans = max({ans, cache[0][i], cache[1][i]});
    }
    cout << ans;
}