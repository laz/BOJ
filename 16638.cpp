#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

char arr[39];
int n, len, ans = -2e9;
string s;

void input() {
    cin >> n >> s;    
}

string infixToPostfix() {
    string postfix = "";
    stack<char> s;

    for(int i = 0; i < len; ++i) {
        if(arr[i] == ' ') continue;
        else if(arr[i] == '(') s.push(arr[i]);
        else if(arr[i] == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(arr[i] == '*') {
            while(!s.empty() && s.top() == '*') {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(arr[i]);
        }
        else if(arr[i] == '+' || arr[i] == '-') {
            while(!s.empty() && (s.top() == '*' || s.top() == '+' || s.top() == '-')) {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(arr[i]);
        }
        else {
            postfix.push_back(arr[i]);
        }
    }

    while(!s.empty()) {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

int calculate(string postfix) {
    stack<ll> s;
    for(char ch : postfix) {
        if(ch == '+') {
            ll num2 = s.top(); s.pop();
            ll num1 = s.top(); s.pop();
            s.push(num1 + num2);
        }
        else if(ch == '-') {
            ll num2 = s.top(); s.pop();
            ll num1 = s.top(); s.pop();
            s.push(num1 - num2);
        }
        else if(ch == '*') {
            ll num2 = s.top(); s.pop();
            ll num1 = s.top(); s.pop();
            s.push(num1 * num2);
        }
        else {
            s.push(ch - '0');
        }
    }
    return s.top();
}

void d(int idx) {
    if(idx >= len) {
        ans = max(ans, calculate(infixToPostfix()));
        return ;
    }

    if(arr[idx] == ')') d(idx + 2);
    else if(idx <= len-7) {
        arr[idx] = '(';
        arr[idx + 6] = ')';
        d(idx + 6);
        arr[idx] = ' ';
        arr[idx + 6] = ' ';
        d(idx + 4);
    }
    else {
        d(idx + 4);
    }
}

int main() {
    fastio;
    input();

    len = 2 * s.length() + 1;
    memset(arr, ' ', sizeof(arr));
    for(int i = 1, idx = 0; idx < s.length(); ++idx, i += 2) {
        arr[i] = s[idx];
    }

    d(0);
    cout << ans;
}