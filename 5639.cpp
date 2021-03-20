#include <iostream>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
};

node* newNode(int v){
    node* n = new node;
    n->value = v;
    n->left = n->right = NULL;
    return n;
}

void insert(node* root, int v){
    if(v < root->value){
        if(root->left == NULL){
            node* n = newNode(v);
            root->left = n;
        }
        else insert(root->left, v);
    }
    else{
        if(root->right == NULL){
            node* n = newNode(v);
            root->right = n;
        }
        else insert(root->right, v);
    }
}

void postorder(node* root){
    if(root->left != NULL) postorder(root->left);
    if(root->right != NULL) postorder(root->right);
    cout << root->value << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    node* root = newNode(n);
    while(cin >> n){
        insert(root, n);
    }
    postorder(root);
}