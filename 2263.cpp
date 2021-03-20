#include <iostream>
#include <vector>
using namespace std;

int inorder[100001], postorder[100001];
int n;

int find(int target){
    for(int i = 0; i < n; ++i)
        if(inorder[i] == target) return i;
    return 0;
}

void preorder(int from, int to, int ffrom, int tto){
    
    if(from >= to || ffrom >= tto) return ;
    else if(from+1 == to){
        cout << inorder[from] << " ";
        return ;
    }

    int root = find(postorder[tto-1]);
    int size = root - from;
    cout << inorder[root] << " ";
    
    preorder(from, root, ffrom, ffrom+size);
    preorder(root+1, to, ffrom+size, tto-1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> inorder[i];
    for(int i = 0; i < n; ++i)
        cin >> postorder[i];
        
    preorder(0, n, 0, n);
}