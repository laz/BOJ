#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string exp, ans;
    cin >> exp;
    stack<char> s;

    for(auto c : exp){
        if('A' <= c && c <= 'Z') ans.push_back(c);
        else{
            if(c == '+' || c == '-'){
                while(!s.empty() && s.top() != '('){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
            else if(c == '*' || c == '/'){
                while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
            else if(c == '(') s.push(c);
            else{   // c == ')'
                while(!s.empty() && s.top() != '('){
                    ans.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    cout << ans;


}
