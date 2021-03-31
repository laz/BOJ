#include <cstdio>

int arr[100];

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    for(int i = 1; i < n; ++i){
        int t = gcd(arr[0], arr[i]);
        printf("%d/%d\n", arr[0]/t, arr[i]/t);
    }
}