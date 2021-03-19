#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
bool visited[100001];
int parent[100001];

void d(int root){
    visited[root] = true;
    for(int child : tree[root]){
        if(visited[child]) continue;
        parent[child] = root;
        d(child);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    d(1);

    for(int i = 2; i <= n; ++i)
        cout << parent[i] << "\n";
}