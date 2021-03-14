#include <cstdio>

void moveN(int from, int to, int tmp, int n){
    if(n == 1){
        printf("%d %d\n", from, to);
        return ;
    }
    moveN(from, tmp, to, n-1);
    moveN(from, to, tmp, 1);
    moveN(tmp, to, from, n-1);
}

int main(){
    int n, rep = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) rep *= 2;
    printf("%d\n", rep-1);
    moveN(1, 3, 2, n);

}