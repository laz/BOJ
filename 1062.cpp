#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string words[50];
bool check[26];
char must[5] = {'a', 'n', 't', 'c', 'i'};
int n, k, tot = 0, ans = 0;

void input() {
    fastio;
    for(int i = 0; i < 5; ++i) check[must[i] - 'a'] = true;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> words[i];
    }
}

void d(int idx, int cnt) {
    
    if(cnt == k) {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            bool readable = true;
            for(int j = 4; j < words[i].size()-4; ++j) {
                if(check[words[i][j] - 'a']) continue;
                readable = false;
                break;
            }
            if(readable) sum++;
        }
        ans = max(ans, sum);
    }

    for(int i = idx; i < 26; ++i) {
        if(check[i]) continue;
        check[i] = true;
        d(i+1, cnt+1);
        check[i] = false;
    }
}

int main() {
    
    input();
    if(k < 5) {
        cout << 0;
        return 0;
    }
    d(0, 5);
    cout << ans;
}