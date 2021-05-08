#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<bool> visited;
int n;

void input() {
    fastio;
    cin >> n;
    visited = vector<bool>(1003002, false);
}

bool isPalindrome(int num) {

    string s = to_string(num);
    int len = s.size(), cnt = len/2;
    
    for(int i = 0; i < cnt; ++i) {
        if(s[i] != s[len-1-i]) return false;
    }
    return true;
}

int main() {
    input();
    
    for(int i = 2; i < 1003002; ++i) {
        if(visited[i]) continue;
        if(i >= n && isPalindrome(i)) {
            cout << i;
            return 0;
        }
        for(int j = i; j < 1003002; j += i) {
            visited[j] = true;
        }
    }
}