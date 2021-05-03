#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int cnt[300001];
int n, k;

void input() {
    fastio;
    cin >> n >> k;
}

int main() {
    input();

    long long ans = 0;
    queue<string> q;
    string s;
    for(int i = 0; i < n; ++i) {
        if(i > k) {
            cnt[q.front().size()]--;
            q.pop();
        }
        cin >> s; 
        cnt[s.size()]++;
        q.push(s);
        if(cnt[s.size()] > 1) {
            ans += cnt[s.size()]-1;
        }
    }
    cout << ans;
}