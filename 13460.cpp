#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct state {
    pii R, B; int d;
    state(pii r, pii b, int dd) {R = r, B = b, d = dd;}
};

pii R, B;
bool visited[10][10][10][10];
char arr[10][10];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 'R') R = {i, j};
            else if(arr[i][j] == 'B') B = {i, j};
            if(arr[i][j] == 'R' || arr[i][j] == 'B') arr[i][j] = '.';
        }
    }
}

state move(pii& a, pii& b, int d, int dir, bool& rFlag, bool& bFlag) {
    pii first, second; bool isFirstRed = true;
    // down
    if(dir == 0) {
        if(a.first > b.first) {
            first = a; second = b;
        }
        else {
            first = b; second = a; isFirstRed = false;
        }
    }
    // right
    else if(dir == 1) {
        if(a.second > b.second) {
            first = a; second = b;
        }
        else {
            first = b; second = a; isFirstRed = false;
        }
    }
    // up
    else if(dir == 2) {
        if(a.first < b.first) {
            first = a; second = b;
        }
        else {
            first = b; second = a; isFirstRed = false;
        }
    }
    // left
    else if(dir == 3) {
        if(a.second < b.second) {
            first = a; second = b;
        }
        else {
            first = b; second = a; isFirstRed = false;
        }
    }

    while(arr[first.first + dx[dir]][first.second + dy[dir]] != '#') {
        first.first += dx[dir];
        first.second += dy[dir];
        if(arr[first.first][first.second] == 'O') {
            isFirstRed ? rFlag = true : bFlag = true;
        }
    }

    while(arr[second.first + dx[dir]][second.second + dy[dir]] != '#') {
        if(second.first + dx[dir] == first.first && second.second + dy[dir] == first.second) {
            if(arr[first.first][first.second] == 'O') {
                isFirstRed ? bFlag = true : rFlag = true;
            }
            break;
        }
        
        second.first += dx[dir];
        second.second += dy[dir];
        if(arr[second.first][second.second] == 'O') {
            isFirstRed ? bFlag = true : rFlag = true;
        }
    }
    if(isFirstRed) return state(first, second, d+1);
    else return state(second, first, d+1);
}

int main() {
    fastio;
    input();
    
    queue<state> q;
    visited[R.first][R.second][B.first][B.second] = true;
    q.push(state(R, B, 0));
    while(!q.empty()) {
        auto [r, b, d] = q.front(); q.pop();
        if(d > 9) break;
        
        for(int i = 0; i < 4; ++i) {
            bool rFlag = false, bFlag = false;
            state nState = move(r, b, d, i, rFlag, bFlag);
            if(bFlag) continue;
            if(rFlag) {
                cout << nState.d;
                return 0;
            }
            if(visited[nState.R.first][nState.R.second][nState.B.first][nState.B.second]) continue;
            visited[nState.R.first][nState.R.second][nState.B.first][nState.B.second] = true;
            q.push(nState);
        }
    }
    cout << -1;
}