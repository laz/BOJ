#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int map[50][50];

bool isSquare(int x, int y, int size){
    if(map[x][y] != map[x+size-1][y]) return false;
    if(map[x][y] != map[x][y+size-1]) return false;
    if(map[x][y] != map[x+size-1][y+size-1]) return false;
    return true;
}

int main(){
    int n, m;
    memset(map, -1, sizeof(map));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    int maxSize = n > m ? m : n, ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(int k = maxSize; k > 0; --k){
                if(i+k-1 < n && j+k-1 < m && isSquare(i, j, k)) {
                    ans = max(ans, k);
                    break;
                }
            }
        }
    }
    printf("%d", ans*ans);
}