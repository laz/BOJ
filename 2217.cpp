#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, v[i] * (i+1));
    cout << ans;

}