#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int map[777][777];
int bl[777][777], br[777][777];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> s;
        for(int j = 1; j <= m; ++j){
            map[i][j] = s[j-1] - '0';
        }
    }

    for(int i = n; i > 0; --i){
        for(int j = 1; j <= m; ++j){
            if(!map[i][j]) continue;
            bl[i][j] = bl[i+1][j-1] + 1;
            br[i][j] = br[i+1][j+1] + 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!map[i][j]) continue;
            int mSize = min(br[i][j], bl[i][j]);
            if(mSize < ans) continue;
            for(int size = mSize; size > 0; --size){
                if(j - (size-1) < 1 || j + (size-1) > m || i + 2*(size-1) > n) continue;
                if(size < ans) continue;
                if(bl[i][j] >= size && bl[i+size-1][j+size-1] >= size && br[i][j] >= size && br[i+size-1][j-(size-1)] >= size){
                    ans = max(ans, size);
                    break;
                }
            }
        }
    }

    cout << ans;

}