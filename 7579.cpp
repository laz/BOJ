#include <cstdio>
#include <algorithm>
using namespace std;

struct app{
    int m, c;
};

int M;
int cache[10001][101];
app apps[101];

int main(){
    int n, totalCost = 0;
    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &apps[i].m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &apps[i].c);
        totalCost += apps[i].c;
    }
    for(int i = 0; i <= n; ++i)
        cache[i][0] = 0;

    int mn = 987654321;
    for(int idx = 1; idx <= n; ++idx){
        for(int cost = 0; cost <= totalCost; ++cost){
            if(apps[idx].c <= cost)
                cache[cost][idx] = max(cache[cost][idx-1], cache[cost-apps[idx].c][idx-1] + apps[idx].m);
            else
                cache[cost][idx] = cache[cost][idx-1];

            if((cache[cost][idx] >= M) && cost < mn)
                mn = cost;
        }
    }
    printf("%d\n", mn);
}