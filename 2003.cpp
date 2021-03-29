#include <iostream>
using namespace std;

int arr[10000];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int ans = 0, s = 0, e = 0, psum = 0;
    while(1){
        if(psum >= m) psum -= arr[s++];
        else if(e == n) break;
        else psum += arr[e++];
        if(psum == m) ans++;
    }
    cout << ans;
}