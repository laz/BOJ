#include <cstdio>
#include <cstring>
using namespace std;

int cache[2002][2002];
int numbers[2002];

int palin(int s, int e){
    if(s == e)
        return 1;

    int& ret = cache[s][e];
    if(ret != -1)
        return ret;
    
    int cnt = e - s + 1;
    while(cnt > 1){
        if(numbers[s++] != numbers[e--]){
            return ret = 0;
        }
        cnt -= 2;
    }
    return ret = 1;
}

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &numbers[i]);
    memset(cache, -1, sizeof(cache));
    int s, e;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &s, &e);
        if(palin(s, e))
            printf("1\n");
        else
            printf("0\n");
    }
}