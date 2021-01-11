#include <cstdio>
using namespace std;

int cache[10001];
int coins[101];
int n, k;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &coins[i]);

    cache[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
            if(j >= coins[i])
                cache[j] += cache[j-coins[i]];

    printf("%d\n", cache[k]);
}
