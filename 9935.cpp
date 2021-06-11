#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

list<char> l;
string s, bomb;

void input() {
    fastio;
    cin >> s >> bomb;
}

int main() {
    input();

    for(char c : s) {
        l.push_back(c);
    }

    for(auto it = l.begin(); it != l.end();) {
        // match?
        bool match = true;
        auto itt = it;
        for(int i = 0; i < bomb.size(); ++i, ++itt) {
            if(bomb[i] != *itt) {
                match = false;
                break;
            }
        }

        if(match) {
            it = l.erase(it, itt);
            // back by size of bomb
            for(int i = 0; i < bomb.size() && it != l.begin(); ++i, --it) { }
        }
        else {
            ++it;
        }
    }

    if(l.empty()) cout << "FRULA";
    else {
        for(auto it = l.begin(); it != l.end(); ++it) {
            cout << *it;
        }
    }
}