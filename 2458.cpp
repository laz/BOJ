#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> adj[501], rev[501];
bool visited[501];
int cache[501];

int dfs(vector<int> v[], int from) {
    visited[from] = true;
    
    int ret = 0;
    for(int to : v[from]) {
        if(visited[to]) continue;
        ret += dfs(v, to) + 1;
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // parse
    for(vector<int> result : results) {
        adj[result[0]].push_back(result[1]);
        rev[result[1]].push_back(result[0]);
    }
    
    // 양방향 dfs 
    for(int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        cache[i] = dfs(adj, i);
        memset(visited, false, sizeof(visited));
        cache[i] += dfs(rev, i);
    }
    
    for(int i = 1; i <= n;++i) {
        if(cache[i] == n-1) 
            answer++;
    }
    
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > v(m);
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        v[i].push_back(a);
        v[i].push_back(b);
    }
    cout << solution(n, v);
}