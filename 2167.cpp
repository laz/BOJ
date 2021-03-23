#include <iostream>
using namespace std;

int map[300][300];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0 ; j < m; ++j){
            cin >> map[i][j];
        }
    }
    int t, x1, x2, y1, y2;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for(int i = x1-1; i <= x2-1; ++i){
            for(int j = y1-1; j <= y2-1; ++j){
                res += map[i][j];
            }
        }
        cout << res << "\n";
    }
}