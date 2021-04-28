#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> adj[10001];
int indegree[10001];
bool visited[10001];

void input() {
    fastio;
    int a, b;
    while(1) {
        cin >> a >> b;
        if(a < 0 && b < 0) exit(0);
        if(!a && !b) break;
        
        adj[a].push_back(b);
        indegree[b]++;
    }
}

int findRoot() {
    bool foundRoot = false;
    int root;
    for(int i = 0; i < 10001; ++i)
        if(!adj[i].empty() && indegree[i] == 0){
            if(foundRoot) return -1;
            foundRoot = true;
            root = i;
        }
    return root;
}

int main() {
    
    int cse = 1;
    while(1) {
        for(int i = 0; i < 10001; ++i) adj[i].clear();
        memset(indegree, 0, sizeof(indegree));
        memset(visited, false, sizeof(visited));
        input();

        int root = findRoot();
        if(root == -1) {
            cout << "Case " << cse++ << " is not a tree.\n";
            continue;
        }

        bool isTree = true;

        queue<int> q;
        visited[root] = true;
        q.push(root);
        while(!q.empty()) {
            int from = q.front(); q.pop();
            for(int to : adj[from]) {
                if(visited[to] || indegree[to] != 1) {
                    isTree = false;
                    break;
                }
                q.push(to);
            }
            if(!isTree) break;
        }
        
        cout << "Case " << cse++ << " is ";
        if(!isTree) cout << "not ";
        cout << "a tree.\n";
    }
}