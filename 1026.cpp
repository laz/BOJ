#include <cstdio>
#include <algorithm>
using namespace std;

int a[50], b[50];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    
    sort(a, a+n, greater<int>());
    sort(b, b+n);
    
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i]*b[i];
    
    printf("%d\n", sum);
}