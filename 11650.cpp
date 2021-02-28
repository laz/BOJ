#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n;
    vector<pair<int, int> > p;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end());
    for(auto a : p)
        cout << a.first << " " << a.second << "\n";
}