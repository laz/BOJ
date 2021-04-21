#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> adj[50];
int arr[50], leaves[50];
int n, m, root;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        if(num == -1) root = i;
        else adj[num].push_back(i);
    }
    cin >> m;
}

void countLeaves(int root) {
    int cnt = 0;
    for(int child : adj[root]) {
        if(child == m) continue;
        countLeaves(child);
        cnt += leaves[child];
    }
    if(cnt == 0) leaves[root] = 1;
    else leaves[root] = cnt;
}

int main() {
    input();
    
    if(root == m) {
        cout << 0;
        return 0;
    }

    countLeaves(root);
    cout << leaves[root];
}