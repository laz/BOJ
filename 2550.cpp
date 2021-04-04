#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int switches[10001], bulbs[10001], cache[10001], path[10001], arr[10001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> switches[i];
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        bulbs[tmp] = i;
    }
    for(int i = 1; i <= n; ++i) arr[i] = bulbs[switches[i]];
    
    int ans = 0, src;
    for(int i = 1; i <= n; ++i){
        int tMax = 0;
        int tmpJ = 0;
        for(int j = 1; j < i; ++j){
            if(arr[j] < arr[i]) {
                // if(cache[i] < cache[j]+1){
                //     path[i] = j;
                //     cache[i] = cache[j]+1;
                // }
                if(tMax <= cache[j]){
                    tMax = cache[j];
                    tmpJ = j;
                }
            }
        }
        // if(ans < cache[i]){
        //     src = i;
        //     ans = cache[i];
        // }
        cache[i] = tMax + 1;
        path[i] = tmpJ;
    }
    
    for(int i = 1; i <= n; ++i){
        if(ans < cache[i]){
            ans = cache[i];
            src = i;
        }
    }

    vector<int> v;
    while(src != 0){
        v.push_back(switches[src]);
        src = path[src];
    }

    sort(v.begin(), v.end());
    cout << ans << "\n";
    for(auto s : v) cout << s << " ";

}