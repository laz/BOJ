#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string arr[10];
bool check[26];
char alphabet[10];
int match[26];
int n, ans = 0, tot = 0;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        for(int j = 0; j < arr[i].size(); ++j) {
            if(check[arr[i][j] - 'A']) continue;
            check[arr[i][j] - 'A'] = true;
            alphabet[tot++] = arr[i][j];
        }
    }
}

int getNum(string& s) {
    int ret = 0;
    for(char& c : s){
        ret *= 10;
        ret += match[c - 'A'];
    }
    return ret;
}

void d(int visited, int cnt) {
    if(visited == (1 << tot)-1) {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += getNum(arr[i]);
        }
        ans = max(ans, sum);
    }

    for(int i = 0; i < tot; ++i) {
        if(visited & (1 << i)) continue;
        match[alphabet[i] - 'A'] = cnt;
        d(visited | (1 << i), cnt-1);
    }
}

int main() {
    input();
    d(0, 9);
    cout << ans;
} 