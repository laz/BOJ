#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp;
    cin >> n;
    v.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < n; ++i)
        cout << v[i] << "\n";
    
}