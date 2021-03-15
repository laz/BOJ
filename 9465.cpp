#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cache[2][100000];
vector<int> v[2];
int n;

int sticker(int x, int y){
    if(y == n-1) return v[x][y];
    else if(y == n-2) return v[x][y] + v[x == 0 ? 1 : 0][n-1];
    
    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = v[x][y] + max({sticker(x == 0 ? 1 : 0, y+1), sticker(0, y+2), sticker(1, y+2)});

    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        v[0] = vector<int>(n);
        v[1] = vector<int>(n);
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < n; ++j)
                cin >> v[i][j];
            
        int ans = 0;
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                ans = max(ans, sticker(i, j));

        cout << ans << "\n";
    }
}