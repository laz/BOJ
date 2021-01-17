#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t, sz;
    bool vps;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        vps = true;
        sz = s.size();
        stack<int> stk;
        if(sz%2)
            vps = false;
        else{
            for(int i = 0 ; i < sz; ++i){
                if(s[i] == '(')
                    stk.push(1);
                else{
                    if(stk.empty() || stk.top() != 1){
                        vps = false;
                        break;
                    }
                    else
                        stk.pop();
                }
            }
        }
        if(stk.empty() && vps) cout << "YES\n";
        else cout << "NO\n";
        while(!stk.empty()) stk.pop();
    }
}