#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int A[21], B[21];
int n, s;

void input() {
    fastio;
    cin >> n >> s;
    for(int i = 1; i <= n/2; ++i) 
        cin >> A[i];
    for(int i = 1; i <= n-n/2; ++i) 
        cin >> B[i];
}

void d(int cnt, int* arr, int sum, int sze, int visited, vector<int>& v) {
    if(cnt == 0) {
        v.push_back(sum);
        return ;
    }
    for(int i = 1; i <= sze; ++i) {
        if(visited & (1 << i)) continue;
        d(cnt-1, arr, sum + arr[i], sze, visited |= (1 << i), v);
    }
}

void getPsum(vector<int>& v, int sze, int* arr) {
    v.reserve(sze*(sze+1)/2);

    for(int i = 1; i <= sze; ++i) {
        d(i, arr, 0, sze, 0, v);
    }
}

int main() {
    input();

    vector<int> psumA; getPsum(psumA, n/2, A); sort(psumA.begin(), psumA.end());
    vector<int> psumB; getPsum(psumB, n-n/2, B); sort(psumB.begin(), psumB.end());

    long long ans = 0;
    for(int& psum : psumA) {
        if(psum == s) ans++;
        int target = s - psum;
        ans += upper_bound(psumB.begin(), psumB.end(), target) - lower_bound(psumB.begin(), psumB.end(), target);
    }
    for(int& psum : psumB) 
        if(psum == s) ans++;
    cout << ans;
}