#include <iostream>
#include <string>
using namespace std;

int sz;

struct stack{
    int value;
    stack* prev;
};

stack* newNode(int n){
    stack* ret = new stack();
    ret->value = n;
    ret->prev = NULL;
    return ret;
}

void push(stack** root, int n){
    stack* stack = newNode(n);
    //top of the stack
    stack->prev = *root;
    *root = stack;
    sz++;
}

int pop(stack** root){
    if(!(*root))
        return -1;
    stack* top = *root;
    *root = (*root)->prev;
    sz--;
    int ret = top->value;
    free(top);
    return ret;
}

int peek(stack** root){
    if((!*root))
        return -1;
    return (*root)->value;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int c, n;
    cin >> c;
    string operation;
    //Sentinel?
    stack* root = NULL;
    sz = 0;
    while(c--){
        cin >> operation;
        if(operation == "push"){
            cin >> n;
            push(&root, n);
        }
        else if(operation == "pop")
            cout << pop(&root) << endl;
        else if(operation == "size")
            cout << sz << endl;
        else if(operation == "empty"){
            if(!root) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else
            cout << peek(&root) << endl;
    }
    


}