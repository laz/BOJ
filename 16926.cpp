#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int arr[305][305], tmp[305][305];
int n, m, r;

void input() {
    cin >> n >> m >> r;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
}

void copy() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            tmp[i][j] = arr[i][j];
        }
    }
}

void spin() {
    copy();
    int layer = min(n, m) / 2;
    
    for(int k = 0; k < layer; ++k) {
        // <
        for(int i = 1+k; i < m-k; ++i) {
            arr[k][i-1] = tmp[k][i];
        }
        // down
        for(int i = k; i < n-1-k; ++i) {
            arr[i+1][k] = tmp[i][k];
        }
        // >
        for(int i = k; i < m-1-k; ++i) {
            arr[n-1-k][i+1] = tmp[n-1-k][i];
        }
        // up
        for(int i = n-1-k; i > k; --i) {
            arr[i-1][m-1-k] = tmp[i][m-1-k];
        }
    }
}

void print() {
    
}

int main() {
    fastio;
    input();

    while(r--) spin();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";;
        }
        cout << "\n";
    }
}