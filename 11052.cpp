#include <iostream>
#include <cstring>
using namespace std;

int cost[1000], cache[10000][1000];
int n;

int d(int idx, int cards){
    if(cards == n) return 0;
    else if(cards > n || idx >= n) return -1e9;
    int& ret = cache[idx][cards];
    if(ret != -1) return ret;

    ret = max(d(idx, cards+idx+1) + cost[idx], d(idx+1, cards));

    return ret;

}
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> cost[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << d(0, 0);
}