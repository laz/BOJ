#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10000];

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < 2*n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr + 2*n);

    int ans = 1e9;
    for(int i = 0; i < n; ++i) 
        ans = min(ans, arr[2*n - i -1] + arr[i]);
    
    printf("%d", ans);
}