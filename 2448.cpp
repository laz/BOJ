#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s[3077];
int n;

void input() {
    fastio;
    cin >> n;
}

void invStar(int from, int sze) {
    for(int i = from, cnt = sze*2-1; i < from+sze; ++i, cnt -= 2) {
        for(int j = 0; j < cnt; ++j) {
            s[i] += ' ';
        }
    }
}

void star(int from, int sze) {
    if(sze == 3) {
        s[from] += '*';
        s[from+1] += "* *";
        s[from+2] += "*****";
    }
    else {
        int sz = sze>>1;
        star(from, sz);
        star(from + sz, sz);
        invStar(from + sz, sz);
        star(from + sz, sz);
    }
}

void padding() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n-1-i; ++j) {
            s[i] += ' ';
        }
    }
}

int main() {
    input();

    padding();
    star(0, n);
    padding();

    for(int i = 0; i < n; ++i) {
        cout << s[i] << '\n';
    }
}