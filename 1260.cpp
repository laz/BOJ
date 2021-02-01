#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, v;

void bfs(int start, vector<vector<int> > map){
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        printf("%d ", curr+1);
        for(int to : map[curr]){
            if(visited[to]) continue;
            visited[to] = true;
            q.push(to);
        }
    }
}

void dfs(int start, vector<vector<int> > map){
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int curr = s.top(); s.pop();
        if(visited[curr]) continue;
        visited[curr] = true;
        printf("%d ", curr+1);
        int sz = map[curr].size();
        for(int to = sz-1; to >= 0; --to){
            if(visited[map[curr][to]]) continue;
            s.push(map[curr][to]);
        }
    }
}

int main(){
    int x, y;
    scanf("%d %d %d", &n, &m, &v);
    vector<vector<int> > map;
    vector<int> tmp;
    for(int i = 0; i < n; ++i)
        map.push_back(tmp);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &x, &y);
        map[x-1].push_back(y-1);
        map[y-1].push_back(x-1);
    }
    for(int i = 0; i < n; ++i)
        sort(map[i].begin(), map[i].end());
    dfs(v-1, map);
    printf("\n");
    bfs(v-1, map);
}