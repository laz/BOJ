#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int A[1001], B[1001];
int T, n, m;

void input() {
    fastio;
    cin >> T >> n;
    for(int i = 1; i <= n; ++i) { 
        cin >> A[i];
        A[i] += A[i-1];
    }
    cin >> m;
    for(int i = 1; i <= m; ++i) { 
        cin >> B[i];
        B[i] += B[i-1];
    }
}

// 모든 부분합
void getPsum(vector<int>& v, int sze, int* arr) {
    v.reserve(sze*(sze+1)/2);
    for(int i = 1; i <= sze; ++i) {   //갯수
        for(int j = i; j <= sze; ++j) {  //starting index
            v.push_back(arr[j] - arr[j-i]);
        }
    }
}

int main() {
    input();

    vector<int> psumA; getPsum(psumA, n, A); sort(psumA.begin(), psumA.end());
    vector<int> psumB; getPsum(psumB, m, B); sort(psumB.begin(), psumB.end());

    long long ans = 0;
    for(int& a : psumA) {
        ans += upper_bound(psumB.begin(), psumB.end(), T-a) - lower_bound(psumB.begin(), psumB.end(), T-a);
    }
    cout << ans;
}