#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    int n, sum=0;
    bool flag = false;
    while(~scanf("%d", &n)){
        if(n < 0)
            flag = true;
        if(flag)
            sum -= abs(n);
        else
            sum += n;
    }
    printf("%d\n", sum);
}