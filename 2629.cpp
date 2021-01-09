#include <cstdio>
#include <algorithm>
using namespace std;

int cache[31][15001];
int chu[31], marbles[7];

int main(){
    int n, m, marble, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &chu[i]);
        sum += chu[i];
    }
    //printf("%d\n", sum);
    sort(chu+1, chu+n+1, greater<int>());
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
        scanf("%d", &marbles[i]);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= sum; ++j){
            //현재 추의 무게
            cache[i][chu[i]] = 1;
            
            //이전추까지 가능했던 무게들에 현재 추의 무게를 더하거나 뺀 무게
            if(cache[i-1][j]){
                cache[i][j] = 1;
                cache[i][abs(j-chu[i])] = 1;
                if(j+chu[i] <= sum) cache[i][j+chu[i]] = 1;
            }
        }
    }

    for(int i = 0; i < m; ++i){
        if(marbles[i] > sum)
            printf("N");
        else if(cache[n][marbles[i]] || marbles[i] == 0)
            printf("Y");
        else
            printf("N");
        printf("%c", i == m-1 ? '\n' : ' ');
    }
}

#if 0
#include <cstdio>
#include <cstring>
#include <cstdlib>

int cache[31][15001];
int chu[31], marbles[7];
int n, sum;

void chuchu(int usedChu, int currentWeight){
    if(usedChu > n || currentWeight > sum) return ;

    int& ret = cache[usedChu][currentWeight];
    if(ret != -1) return ;

    ret = 1;
    chuchu(usedChu + 1, currentWeight + chu[usedChu]);
    chuchu(usedChu + 1, currentWeight);
    chuchu(usedChu + 1, abs(currentWeight - chu[usedChu]));
}

int main(){
    int m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &chu[i]);
        sum += chu[i];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
        scanf("%d", &marbles[i]);
    
    memset(cache, -1, sizeof(cache));

    chuchu(0, 0);
    for(int i = 0; i < m; ++i){
        if(marbles[i] > sum)
            printf("N");
        else if(cache[n][marbles[i]] == 1)
            printf("Y");
        else
            printf("N");
        printf("%c", i == m-1 ? '\n' : ' ');
    }
}
#endif