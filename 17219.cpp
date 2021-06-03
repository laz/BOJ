#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

unordered_map<string, string> um;
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    string name, password;
    for(int i = 0; i < n; ++i) {
        cin >> name >> password;
        um[name] = password;
    }
}

int main() {
    input();
    
    string name;
    for(int i = 0; i < m; ++i) {
        cin >> name;
        cout << um[name] << '\n';
    }   
}