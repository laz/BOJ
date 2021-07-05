#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

vector<string> op;
int n;

void input() {
    fastio;
    while(1) {
        string tmp; cin >> tmp;
        if(tmp == "QUIT") exit(0);
        if(tmp == "END") break;
        op.push_back(tmp);
    }
    cin >> n;
}

int main() {
    while(1) {
        input();
        while(n--) {
            bool error = false;
            int num; cin >> num;

            stack<ll> stk;
            stk.push(num);
            
            for(int i = 0; i < op.size(); ++i) {
                if(op[i] == "NUM") {
                    ll x = stol(op[++i]);
                    stk.push(x);
                }
                else if(op[i] == "POP") {
                    if(stk.empty()) {
                        error = true;
                        break;
                    }
                    stk.pop();
                }
                else if(op[i] == "INV") {
                    stk.top() = -stk.top();
                }
                else if(op[i] == "DUP") {
                    stk.push(stk.top());
                }
                else if(op[i] == "SWP") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    stk.push(a); stk.push(b);
                }
                else if(op[i] == "ADD") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    if(abs(a+b) > 1e9) {
                        error = true;
                        break;
                    }
                    stk.push(a+b);
                }
                else if(op[i] == "SUB") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    if(abs(b-a) > 1e9) {
                        error = true;
                        break;
                    }
                    stk.push(b-a);
                }
                else if(op[i] == "MUL") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    if(abs(a*b) > 1e9) {
                        error = true;
                        break;
                    }
                    stk.push(a*b);
                }
                else if(op[i] == "DIV") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    if(a == 0) {
                        error = true;
                        break;
                    }
                    stk.push(b/a); 
                }
                else if(op[i] == "MOD") {
                    if(stk.size() < 2) {
                        error = true;
                        break;
                    }
                    ll a = stk.top(); stk.pop();
                    ll b = stk.top(); stk.pop();
                    if(a == 0) {
                        error = true;
                        break;
                    }
                    stk.push(b%a);
                }
            }
            if(error || stk.size() != 1) cout << "ERROR\n";
            else cout << stk.top() << "\n";
        }
        op.clear();
        cout << "\n";
    }
}