#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> babyShark;
int sze = 2, cnt = 0;

bool visited[20][20];
int arr[20][20];
int n;

struct edible{
    int dist, x, y;
    edible(int a, int b, int c) {
        dist = a, x = b, y = c;
    }
    bool operator<(const edible& tmp) const {
        if(dist != tmp.dist) return dist > tmp.dist;
        else if(x != tmp.x) return x > tmp.x;
        return y > tmp.y;
    }
};

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                babyShark = {i, j};
                arr[i][j] = 0;
            }
        }
    }   
}

void find(priority_queue<edible>& pq) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int> > > q;
    visited[babyShark.first][babyShark.second] = true;
    q.push({0, babyShark});

    while(!q.empty()) {
        auto from = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = from.second.first + dx[i], ny = from.second.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || arr[nx][ny] > sze) continue;
            visited[nx][ny] = true;
            q.push({from.first+1, {nx, ny}});

            if(arr[nx][ny] && arr[nx][ny] < sze)
                pq.push(edible(from.first+1, nx, ny));
        }
    }
}

void eat(edible fish) {
    babyShark.first = fish.x; babyShark.second = fish.y;
    arr[fish.x][fish.y] = 0;
    cnt++;
    if(cnt == sze) {
        sze++;
        cnt = 0;
    }
}

int main() {
    input();

    int ans = 0;
    while(1) {
        priority_queue<edible> pq;
        find(pq);
        if(pq.empty()) {
            cout << ans;
            return 0;
        }
        else {
            eat(pq.top());
            ans += pq.top().dist;
        }
    }
}