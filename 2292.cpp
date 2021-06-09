#include <cstdio>

int main(){
    int n; scanf("%d", &n);
    int t = 1, tt = 1;
    while(1){
        if(n <= tt) break;
        tt += 6*t;
        t++;
    }
    printf("%d", t);
}