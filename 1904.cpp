#include <cstdio>

int n, num[3];

int main(){

    num[0]=1;
    num[1]=2;
    scanf("%d", &n);
    for(int i = 2 ; i < n; i++){
        num[2]=(num[0]+num[1])%15746;
        num[0]=num[1];
        num[1]=num[2];
    }
    if(n<=2) printf("%d\n", num[n-1]);
    else printf("%d\n", num[2]);
}
