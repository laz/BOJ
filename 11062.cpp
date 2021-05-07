#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[1000], cache[1000][1000][2];
int n;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int d(int from, int to, bool turn) {

    int& ret = cache[from][to][turn];
    if(ret != -1) return ret;

    if(from == to) {
        if(!turn) return ret = arr[from];
        else return ret = 0;
    }

    if(!turn) ret = max(d(from+1, to, !turn) + arr[from], d(from, to-1, !turn) + arr[to]);
    else ret = min(d(from+1, to, !turn), d(from, to-1, !turn));
    
    return ret;
}

int main() {
    fastio;
    int t; cin >> t;

    while(t--) {
        input();
        memset(cache, -1, sizeof(cache));
        cout << d(0, n-1, 0) << "\n";
    }
}