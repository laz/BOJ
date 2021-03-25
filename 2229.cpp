#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[1005], cache[1005];
int n;

void input(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
}

int d(int idx){
    if(idx == n) return 0;

    int& ret = cache[idx];
    if(ret != -1) return ret;

    ret = 0;
    int mn = 1e9, mx = 0;
    for(int i = idx; i < n; ++i){
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        ret = max(ret, d(i+1) + (mx - mn));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    memset(cache, -1, sizeof(cache));
    cout << d(0);
}