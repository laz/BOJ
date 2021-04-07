#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int rules[10000][3];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, d; cin >> n >> k >> d;
    for(int i = 0; i < k; ++i){
        cin >> rules[i][0] >> rules[i][1] >> rules[i][2];
    }

    int s = 0, e = n+1;
    while(s < e){
        int mid = (s+e)/2;
        ll sum = 0;
        for(int i = 0; i < k; ++i){
            int to = min(rules[i][1], mid);
            if(to < rules[i][0]) continue;
            sum += (to- rules[i][0]) / rules[i][2] + 1;
        }
        if(sum < d) s = mid+1;
        else e = mid;
    }
    cout << s << endl;
}