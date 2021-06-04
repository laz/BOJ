#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int cache[50001];
int n;

void input() {
    fastio;
    cin >> n;
}

int d(int num) {
    int& ret = cache[num];
    if(ret != -1) return ret;

    ret = 1e9;
    for(int i = 1; i*i <= num; ++i) {
        ret = min(ret, d(num - i*i) + 1);
    }
    return ret;
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));
    cache[0] = 0;
    cout << d(n);
}