#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool visited[51];
string s;
int n;

void input() {
    cin >> s;
}

void d(int idx, string res) {
    if(idx == s.size()) {
        cout << res;
        exit(0);
    }
    
    int check;
    // 1
    check = s[idx] - '0';
    if(check <= n && !visited[check]) {
        visited[check] = true;
        d(idx+1, res + s[idx] + " ");
        visited[check] = false;
    }

    // 2
    if(idx >= s.size()-1) return ;
    string tmp = ""; 
    tmp.push_back(s[idx]), tmp.push_back(s[idx+1]);
    check = stoi(tmp);
    if(check <= n && !visited[check]) {
        visited[check] = true;
        d(idx+2, res + tmp + " ");
        visited[check] = false;
    }
}

int main() {
    fastio;
    input();
    
    n = s.size() < 10 ? s.size() : (s.size() - 9) / 2 + 9;
    d(0, "");
}