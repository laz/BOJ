#include <cstdio>

int cache[100][21];
int cost[21], value[21];

int max(int a, int b){ return a > b ? a : b; }
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &cost[i]);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &value[i]);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < 100; ++j){
            if(cost[i] <= j)
                cache[j][i] = max(cache[j][i-1], cache[j-cost[i]][i-1] + value[i]);
            else
                cache[j][i] = cache[j][i-1];
        }
    }
    printf("%d\n", cache[99][n]);
}