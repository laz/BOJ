#include <cstdio>
using namespace std;

int k;
int coins[10];

int main(){
    int n, cnt = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%d", &coins[i]);

    while(k){
        cnt += k / coins[--n];
        k %= coins[n];
    }
    printf("%d\n", cnt);
}