#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const string& a, const string& b){
    int asize = a.size(), bsize = b.size();
    if(asize < bsize) return true;
    else if(asize > bsize) return false;
    else return a < b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    vector<string> v;
    v.reserve(n);
    for(int i = 0 ;i < n; ++i){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    int len = v.size();
    cout << v[0] << "\n";
    for(int i = 1; i < len; ++i){
        if(v[i] != v[i-1])
            cout << v[i] << "\n";
    }
}