#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[26][26];
bool visited[26][26];
int n;

int dfs(int x, int y){
    int ret = 1;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(!map[nx][ny] || visited[nx][ny]) continue;
        visited[nx][ny] = true;
        ret += dfs(nx, ny);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%1d", &map[i][j]);

    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            if(map[i][j] && !visited[i][j]){
                cnt++;
                visited[i][j] = true;
                ans.push_back(dfs(i, j));
            }
        }
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for(int total : ans)
        printf("%d\n", total);
}