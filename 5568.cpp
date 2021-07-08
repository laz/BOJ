#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

unordered_set<int> us;
bool visited[11];
int arr[11];
int n, k, ans = 0;

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void d(int cnt, string s) {
    if(cnt) {
        for(int i = 0; i < n; ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            d(cnt-1, s + to_string(arr[i]));
            visited[i] = false;
        }
    }
    else {
        int num = stoi(s);
        if(us.find(num) == us.end()) {
            us.insert(num);
            ans++;
        }
    }
}

int main() {
    fastio;
    input();
    d(k, "");
    cout << ans;
}