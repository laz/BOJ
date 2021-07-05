#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

set<string> cache[11];
int n, m, k, ans = 0;
bool able = false;

void input() {
    fastio;
    cin >> n >> k;
}

void d(string& num, int _cnt) {
    if(_cnt == 0) {
        ans = max(ans, stoi(num));
        able = true;
        return ;
    }

    auto it = cache[_cnt].find(num);
    if(it != cache[_cnt].end()) return ;
    cache[_cnt].insert(num);
    
    for(int i = 0; i < m; ++i) {
        for(int j = i+1; j < m; ++j) {
            if(num[j] == '0' && i == 0) continue;
            swap(num[i], num[j]);
            d(num, _cnt-1);
            swap(num[i], num[j]);
        }
    }
}

int main() {
    input();
    string num = to_string(n);
    m = num.size();

    d(num, k);
    cout << (able ? ans : -1);
}