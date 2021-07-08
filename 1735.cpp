#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int a, b, c, d;

void input() {
    cin >> a >> b >> c >> d;
}

ll gcd(int aa, int bb) {
    if(bb == 0) return aa;
    return gcd(bb, aa%bb);
}

int main() {
    fastio;
    input();

    ll lcm = b * d / gcd(b,d);
    ll A = lcm/b*a + lcm/d*c;
    ll d = gcd(A, lcm);
    cout << A/d << " " << lcm/d;
}