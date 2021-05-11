#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 987654321;

int cost[16][16], cache[1<<16];
int n, minOn;

int min(int a, int b) { return a > b ? b : a; }
int fix(int visited){
    if(__builtin_popcount(visited) >= minOn) return 0;

    int& ret = cache[visited];
    if(ret != -1) return ret;
    
    ret = MAX;
    //모든 발전소 중
    for(int on = 0; on < n; ++on)
        //켜져있으면
        if(visited & (1 << on))
            //모든 발전소 중
            for(int to = 0; to < n; ++to)
                //꺼진 얘를 찾아서
                if(visited & ~(1 << to))
                    ret = min(ret, fix(visited | (1 << to)) + cost[on][to]);

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string initStatusString;
    int initStatus = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> cost[i][j];
    cin >> initStatusString >> minOn;

    for(int i = 0; i < n; ++i)
        if(initStatusString[i] == 'Y')
            initStatus |= (1 << i);
    
    if(!initStatus){
        if(!minOn)
            cout << 0 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    memset(cache, -1, sizeof(cache));
    cout << fix(initStatus) << endl;
}