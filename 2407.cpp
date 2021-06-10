#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string cache[111][111];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
}

string add(string a, string b) {
    vector<int> v(max(a.size(), b.size())+1);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.size(); ++i) v[i] += a[i]-'0';
    for(int i = 0; i < b.size(); ++i) v[i] += b[i]-'0';

    string ret = "";
    for(int i = 0; i < v.size()-1; ++i) {
        ret.push_back((v[i]%10) + '0');
        if(v[i] >= 10) v[i+1]++;
    }
    if(v[v.size()-1]) {
        ret.push_back('1');
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

string bionimal(int nn, int r) {
    if(r == 0 || nn == r) return "1";
    
    string& ret = cache[nn][r];
    if(ret != "") return ret;

    return ret = add(bionimal(nn-1, r-1), bionimal(nn-1, r));
}

int main() {
    input();
    
    cout << bionimal(n, m);
}