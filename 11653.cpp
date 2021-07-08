#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int n;

void input() {
    cin >> n;
}

int main() {
    fastio;
    input();
    for(int i = 2; i <= n; ++i) {
        while(n%i == 0) {
            cout << i << "\n";
            n /= i;
        }
    }
}