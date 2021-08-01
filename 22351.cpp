#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

string s;

void input() {
    cin >> s;
}

int d(int num) {
    for(int i = 0; i < s.length(); ) {
        string target = to_string(num);
        int sz = target.length();
        for(int j = 0; j < sz; ++j) {
            if(target[j] != s[i+j]) return -1;
        }
        i += sz;
        num++;
    }
    return num;
}

int main() {
    fastio;
    input();
    for(int i = 1; i <= 999; ++i) {
        int ret = d(i);
        if(ret == -1) continue;
        cout << i << " " << ret-1;
        return 0;
    }
}