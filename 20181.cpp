#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll psum[100001], cache[100001];
int n, k;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> psum[i]; psum[i] += psum[i-1];
    }
    
    int s = 1, e = 1;
    ll sum = 0, ans = 0, tmax = 0;
    while(e <= n) {
        sum = psum[e] - psum[s-1];
        if(sum >= k){
            tmax = max(tmax, cache[s-1]);
            cache[e] = max(cache[e], tmax + sum - k);
            s++;
        }
        else e++;
    }
    for(int i = 1; i <= n; ++i){
        ans = max(ans, cache[i]);
    }
    cout << ans;
}