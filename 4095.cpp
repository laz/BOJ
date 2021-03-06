#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        if(!n && !m) return 0;
        int ans = 0;
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> map[i][j];
            }
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(!map[i][j]) continue;
                map[i][j] = min({map[i-1][j-1], map[i][j-1], map[i-1][j]}) + 1;
                ans = max(ans, map[i][j]);
            }
        }
        cout << ans << "\n";
    }
}