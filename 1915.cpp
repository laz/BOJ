#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> s;
        for(int j = 1; j <= m; ++j){
            map[i][j] = s[j-1] - '0';
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!map[i][j]) continue;
            map[i][j] = min({map[i-1][j-1], map[i-1][j], map[i][j-1]}) + 1;
            ans = max(ans, map[i][j]);
        }
    }
    cout << ans*ans;
}