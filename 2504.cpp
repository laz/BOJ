#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

string str;

void input() {
    cin >> str;
}

int main() {
    fastio;
    input();

    // check validity
    stack<char> s;
    for(auto& c : str) {
        if(c == ')' && !s.empty() && s.top() == '(') {
            s.pop();
        }
        else if(c == ']' && !s.empty() && s.top() == '[') {
            s.pop();
        }
        else s.push(c);
    }
    if(!s.empty()) {
        cout << 0;
        return 0;
    }
    
    stack<string> stk;
    int ans = 0;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') {
            if(str[i+1] == ')') {
                stk.push("2");
                i++;
            }
            else stk.push("(");
        }
        else if(str[i] == '[') {
            if(str[i+1] == ']') {
                stk.push("3");
                i++;
            }
            else stk.push("[");
        }
        else if(str[i] == ')') {
            int tmp = 0;
            while(stk.top() != "(") {
                tmp += stoi(stk.top());
                stk.pop();
            }
            stk.pop();
            stk.push(to_string(2*tmp));
        }
        else if(str[i] == ']') {
            int tmp = 0;
            while(stk.top() != "[") {
                tmp += stoi(stk.top());
                stk.pop();
            }
            stk.pop();
            stk.push(to_string(3*tmp));
        }
    }
    while(!stk.empty()) {
        ans += stoi(stk.top());
        stk.pop();
    }
    cout << ans;
}