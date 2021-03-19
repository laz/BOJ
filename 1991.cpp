#include <iostream>
#include <string>
using namespace std;

pair<int, int> adj[26];

void preorder(int parent){
    cout << (char)(parent+65);
    if(adj[parent].first > 0) preorder(adj[parent].first);
    if(adj[parent].second > 0) preorder(adj[parent].second);
}

void inorder(int parent){
    if(adj[parent].first > 0) inorder(adj[parent].first);
    cout << (char)(parent+65);
    if(adj[parent].second > 0) inorder(adj[parent].second);
}

void postorder(int parent){
    if(adj[parent].first > 0) postorder(adj[parent].first);
    if(adj[parent].second > 0) postorder(adj[parent].second);
    cout << (char)(parent+65);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        char a, b, c;
        cin >> a >> b >> c;
        if(b != '.') adj[a-65].first = b-65;
        if(c != '.') adj[a-65].second = c-65;
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}