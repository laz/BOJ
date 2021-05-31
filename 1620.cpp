#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

unordered_map<string, int> um;
string names[100002];
int n, m, idx = 1;

void input() {
    fastio;
    cin >> n >> m;
    string name;
    for(int i = 0; i < n; ++i) {
        cin >> name;
        um[name] = idx++;
        names[i] = name;
    }
}

int main() {
    input();
    
    string q;
    for(int i = 0; i < m; ++i) {
        cin >> q;
        if('0' < q[0] && q[0] <= '9') {
            int idx = stoi(q);
            cout << names[idx-1] << "\n";
        }
        else
            cout << um[q] << "\n";
    }
}