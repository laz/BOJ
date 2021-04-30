#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int cache[30][30];
int t;

void input() {
    fastio;
    cin >> t;
}

int binomial(int n, int k) {
    int& ret = cache[n][k];
    if(ret != -1) return ret;

    if(k == 0 || n == k) return 1;
    return ret = binomial(n-1, k-1) + binomial(n-1, k);
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));
    while(t--) {
        int n, k; cin >> k >> n;
        cout << binomial(n, k) << "\n";
    }
}