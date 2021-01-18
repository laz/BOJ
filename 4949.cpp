#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    bool peace;
    while(1){
        stack<int> stk;
        string s;
        getline(cin, s);
        if(s == ".") break; 
        peace = true; 
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') stk.push(1);
            else if(s[i] == '[') stk.push(2);
            else if(s[i] == ')'){
                if(stk.empty() || stk.top() != 1){
                    peace = false;
                    break;
                }
                stk.pop();
            }
            else if(s[i] == ']'){
                if(stk.empty() || stk.top() != 2){
                    peace = false;
                    break;
                }
                stk.pop();
            }
        }
        if(stk.empty() && peace) printf("yes\n");
        else printf("no\n");
    }
}