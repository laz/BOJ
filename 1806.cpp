#include <iostream>
using namespace std;

int arr[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    int ans = 1e9, s = 0, e = 0, psum = 0;
    while(1){
        if(psum >= m) psum -= arr[s++];
        else if(e == n) break;
        else psum += arr[e++];
        if(psum >= m) ans = min(e-s, ans);
    }

    cout << (ans == 1e9 ? 0 : ans);

}