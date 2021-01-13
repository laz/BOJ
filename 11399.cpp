#include <cstdio>
#include <algorithm>
using namespace std;

int t[1001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);

    sort(t+1, t+n+1);
    
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += (n-i+1) * t[i];

    printf("%d\n", ans);
}