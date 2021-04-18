#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[100] = {
    0, 0, 
    1, 7, 4, 2, 6, 8,
    10, 18, 22, 20, 28, 68, 88,
    108, 188, 200, 208, 288, 688, 888
};
int t;

void input() {
    fastio;
    cin >> t;
}

string getMax(int num) {
    string ret = "";

    if(num%2) {
        ret += '7';
        num -= 3;
    }

    while(num) {
        ret += '1';
        num -= 2;
    }

    return ret;
}

string getMin(int n) {
    if(n <= 21) return to_string(arr[n]);
    
    int cnt = 0;
    while(n > 21) {
        n -= 7;
        cnt++;
    }
    string ret = to_string(arr[n]);
    while(cnt--) {
        ret += '8';
    }
    return ret;
}

int main() {
    input();
    
    while(t--) {
        int num; cin >> num;
        cout << getMin(num) << " " << getMax(num) << "\n";
    }
}