#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int x, y;

void input() {
    fastio;
    cin >> x >> y;
}

int main() {
    input();

    int Z = 100*1LL*y/x;
    long long s = 0, e = 1e10;
    while(s < e) {
        int mid = (s + e) / 2;
        int rate = 100*1LL*(y+mid)/(x+mid);
        if(rate > Z) e = mid;
        else s = mid+1;
    }
    if(s >= 1e9+1) cout << -1;
    else cout << s;
}