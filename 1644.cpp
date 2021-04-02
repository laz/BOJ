#include <iostream>
#include <vector>
using namespace std;

int primes[283333];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<bool> arr(n+1, true);
    int cnt = 0;
    for(int i = 2; i <= n; ++i){
        if(arr[i]){
            primes[cnt++] = i;
            for(int j = i*2; j <= n; j += i)
                arr[j] = false;
        }
    }

    int s = 0, e = 0, ans = 0, psum = 0;
    while(1){
        if(psum > n) psum -= primes[s++];
        else if(e == cnt) break;
        else psum += primes[e++];
        if(psum == n) ans++;
    }
    cout << ans;

    
}