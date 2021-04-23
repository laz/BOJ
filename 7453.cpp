#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[4000][4];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < 4; ++j) 
            cin >> arr[i][j];
}   

int main() {
    input();

    vector<int> v; 
    v.reserve(n*n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            v.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int target = -(arr[i][0] + arr[j][1]);
            ans += upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target);
        }
    }
    cout << ans;
}