#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
float m;
int candies[5000][2], cache[10000];

int d(int idx, int money){
    if(idx == n) return 0;
    
    int& ret = cache[money];
    if(ret != -1) return ret;

    ret = 0;
    if((m-money) >= candies[idx][1]) ret = d(idx, money + candies[idx][1]) + candies[idx][0];
    ret = max(ret, d(idx+1, money));
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c;
    float p;
    while(cin >> n >> m){
        if(!n && !m) break;
        memset(cache, -1, sizeof(cache));
        m *= 100;
        for(int i = 0; i < n; ++i){
            cin >> c >> p;
            candies[i][0] = c;
            candies[i][1] = p*100;
        }
        cout << d(0, 0) << "\n";
    }
    
}