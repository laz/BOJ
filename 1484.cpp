#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int curr = 2, prev = 1, dif = 0;
    vector<int> ans;
    while(curr > prev) {
        dif = curr*curr - prev*prev;
        if(dif == n) ans.push_back(curr);

        if(dif <= n) curr++;
        else prev++;
    }
    
    if(ans.empty()) cout << -1;
    else {
        for(auto a : ans) cout << a << "\n";
    }
    
}