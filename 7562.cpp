#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int visited[301][301];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, y, tx, ty;
        cin >> n >> x >> y >> tx >> ty;
        if(x == tx && y == ty){
            cout << 0 << "\n";
            continue;
        }
        bool notFound = true;
        memset(visited, false, sizeof(visited));
        queue<pair<int, int> > q;
        q.push({x, y});
        while(notFound){
            auto curr = q.front(); q.pop();
            for(int i = 0; i < 8; ++i){
                int nx = curr.X + dx[i], ny = curr.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(nx == tx && ny == ty){
                    cout << visited[curr.X][curr.Y] + 1 << "\n";
                    notFound = false;
                    break;
                }
                if(visited[nx][ny]) continue;
                visited[nx][ny] = visited[curr.X][curr.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
}