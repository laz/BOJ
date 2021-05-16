#include <cstdio>
#include <cstring>
#include <limits>
using namespace std;

const int MAX = 987654321;

int n, done;
int cost[16][16], cache[16][1<<16];

int min(int a, int b) { return a > b ? b : a; }
int tsp(int from, int visited){
    // Base case
    if(visited == done){
        if(cost[from][0] == 0) return MAX;
        return cost[from][0];
    }
    
    int& ret = cache[from][visited];
    if(ret != -1) return ret;

    ret = MAX;
    for(int to = 0; to < n; ++to){
        if((visited >> to) & 1 || cost[from][to] == 0) continue;
        ret = min(ret, tsp(to, visited | 1 << to) + cost[from][to]);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &cost[i][j]);
            
    done = (1 << n) - 1;
    memset(cache, -1, sizeof(cache));
    printf("%d\n", tsp(0, 1));
}