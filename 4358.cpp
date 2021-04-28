#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

map<string, int> mp;
int cnt = 0, tot = 0;

void input() {
    fastio;
    cout << fixed << setprecision(4);
    string name;
    while(getline(cin, name)) {
        tot++;
        mp[name]++;
    }
}

int main() {
    input();
    for(auto& m : mp) {
        cout << m.first << " " << (double)m.second/tot*100 << "\n";
    }
}