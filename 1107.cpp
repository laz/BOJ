#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string target;
int n, answer;
bool broken[10];

void input() {
    fastio;
    int numBroken, num;
    cin >> target >> numBroken;
    n = stoi(target);
    for(int i = 0; i < numBroken; ++i) {
        cin >> num;
        broken[num] = true;
    } 
}

void d(string& num) {
    for(int i = 0; i < 10; ++i) {
        if(broken[i]) continue;
        string newNum = num + to_string(i);
        answer = min(answer, (int)newNum.size() + abs(n - stoi(newNum)));
    
        if(newNum.size() < 6) 
            d(newNum);
    }
}

int main() {
    input();

    answer = abs(n-100);

    string num = "";
    d(num);
    cout << answer;
}