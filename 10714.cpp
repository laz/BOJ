#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

ll cache[2000][2000];
int arr[2000];
int n;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

int cFrom(int from) {
    return from-1 == -1 ? n-1 : from-1;
}
int cTo(int to) {
    return to+1 == n ? 0 : to+1;
}

ll d(int from, int to, int turn) {

    ll& ret = cache[from][to];
    if(ret != -1) return ret;

    if(from == to) return ret = 0;
    
    if(!turn) 
        ret = max(d(cFrom(from), to, !turn) + arr[cFrom(from)], d(from, cTo(to), !turn) + arr[to]);
    else {
        if(arr[cFrom(from)] > arr[to]) ret = d(cFrom(from), to, !turn);
        else ret = d(from, cTo(to), !turn);
    }
    return ret;
}

int main() {
    input();
    memset(cache, -1, sizeof(cache));

    ll ans = d(n-1, 0, 1) + arr[n-1];
    for(int i = 0; i < n-1; ++i) {
        ans = max(ans, d(i, i+1, 1) + arr[i]);
    }
    cout << ans;
}