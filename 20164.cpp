#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mx = 0, mn = 1e9;

int countOdd(int n){
    int ret = 0;
    while(n >= 10){
        if(n%2 == 1) ret++;
        n /= 10;
    }
    if(n%2 == 1) ret++;
    return ret;
}

void odd(int n, int cnt){

    if(n < 10){
        mx = max(mx, cnt);
        mn = min(mn, cnt);
        return ;
    }
    if(n < 100) {
        int num = n/10 + n%10;
        odd(num, cnt + countOdd(num));
        return ;
    }
    
    string s = to_string(n);
    for(int i = 1; i < s.length()-1; ++i){
        for(int j = i+1; j < s.length(); ++j){
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j-i);
            string s3 = s.substr(j, s.length() - j);
            int num = stoi(s1) + stoi(s2) + stoi(s3);
            odd(num, cnt + countOdd(num));
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    odd(n, countOdd(n));
    cout << mn << " " << mx;
}