#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 987654321;

int cost[100002], dist[100001];
int mCost[100002], psum[100001];

int main(){
    int n, mn = MAX, midx, trash;
    scanf("%d", &n);
    
    scanf("%d", &dist[0]);
    psum[0] = dist[0];
    for(int i = 1 ; i < n-1; ++i){
        scanf("%d", &dist[i]);
        psum[i] = psum[i-1] + dist[i];
    }

    for(int i = 0; i < n-1; ++i){
        scanf("%d", &cost[i]);
        if(cost[i] < mn){
            midx = i;
            mn = cost[i];
        }
        mCost[i] = mn;
    }
    scanf("%d", &trash);
    

    long long ans = 0;
    for(int i = 0; i < midx; ++i)
        ans += 1LL * mCost[i] * dist[i];
    ans += 1LL * (psum[n-2] - psum[midx-1]) * mn;
    printf("%lld\n", ans);
}

