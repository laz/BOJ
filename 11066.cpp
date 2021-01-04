#include <cstdio>
#include <cstring>
using namespace std;

int cache[501][501], size[501], sum[501];
int k;

int min(int a, int b) { return a > b ? b : a; }
int findMin(int x, int y){
    
    if(x == y) return 0;

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = __INT_MAX__;
    for(int i = x; i < y; ++i)
        ret = min(ret, findMin(x, i) + findMin(i+1, y) + sum[y] - sum[x-1]);
        
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &k);
        memset(cache, -1, sizeof(cache));
        for(int j = 1; j <= k; ++j){
            scanf("%d", &size[j]);
            sum[j] = sum[j-1] + size[j];
        }
        printf("%d\n", findMin(1, k));
    }

}