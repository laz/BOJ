#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> x;

    sort(arr, arr+n+1);
    int s = 1, e = n, ans = 0;
    while(s < e){
        int t = arr[s] + arr[e];
        if(t == x) ans++;

        if(t <= x) s++;
        else e--;
    }
    cout << ans;


}