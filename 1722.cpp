#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

ll fact[21];
int n, type;

void input() {
    fastio;
    cin >> n;
}

int main() {
    input();

    fact[0] = 1;
    for(int i = 1; i <= 20; ++i) {
        fact[i] = i * fact[i-1];
    }

    list<int> lst;
    for(int i = 1; i <= n; ++i) lst.push_back(i);
    
    cin >> type;
    if(type == 1) {
        ll target; cin >> target;
        target--;

        for(int i = n-1; i > 0; --i) {
            int offset = target / fact[i];
            auto it = lst.begin();
            for(int j = 0; j < offset; ++j, ++it) {};
            cout << *it << " ";
            lst.erase(it);
            target %= fact[i];
        }
        cout << lst.front();
    }
    else {
        ll ans = 1;
        
        for(int i = n-1; i > 0; --i) {
            int target; cin >> target; 
            auto it = lst.begin(); int offset = 0;
            for(; it != lst.end(); ++it, ++offset) {
                if(*it == target) break;
            }
            ans += fact[i] * offset;
            lst.erase(it);
        }
        cin >> type;
        cout << ans;
    }

}