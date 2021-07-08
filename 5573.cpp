#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int cache[1005][1005];
bool arr[1005][1005];
int n, m, k;

void input() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    fastio;
    input();
    
    cache[1][1] = k-1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i == 1 && j == 1) continue;

            int left, up;
            // 오
            if(arr[i][j-1]) {
                if(cache[i][j-1] & 1) left = cache[i][j-1]/2+1;
                else left = cache[i][j-1]/2;
            }
            else left = cache[i][j-1]/2;

            // 아
            if(!arr[i-1][j]) {
                if(cache[i-1][j] & 1) up = cache[i-1][j]/2+1;
                else up = cache[i-1][j]/2;
            }
            else up = cache[i-1][j]/2;

            cache[i][j] = left + up;
        }
    }

    int x = 1, y = 1;
    while(x <= n && y <= m) {
        // inv
        if(cache[x][y] & 1) {
            // 오
            if(arr[x][y]) x++;
            else y++;
        }
        else {
            if(arr[x][y]) y++;
            else x++;
        }   
    }
    cout << x << " " << y;
}