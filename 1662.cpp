#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool visited[50];
string s;

void input() {
    fastio;
    cin >> s;
}

int d(int idx) {
    int ret = 0;

    for(int i = idx; i < s.size(); ++i) {
        if(!visited[i] && s[i] == '(') {
            visited[i] = true;
            ret += (s[i-1]-'0') * d(i+1) - 1;
        }
        else if(!visited[i] && s[i] == ')') {
            visited[i] = true;
            return ret;
        }
        else if(!visited[i]) {
            visited[i] = true;
            ret++;
        }
    }
    return ret;
}

int main() {
    input();
    cout << d(0);
}