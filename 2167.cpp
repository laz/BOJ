#include <iostream>
using namespace std;

int map[301][301], psum[301][301];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1 ; j <= m; ++j){
            cin >> map[i][j];
        }
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            psum[i][j] = map[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

    int t, x1, x2, y1, y2;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1] << "\n";
    }
}