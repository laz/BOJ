#include <cstdio>
#include <algorithm>
using namespace std;

int arr[101];

int main(){
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    if(arr[n-1] != l) arr[n++] = l;
    int left = 0, right = l+1;
    while(left < right){
        int mid = (left + right) / 2;
        int start = 0, cnt = 0, idx = 0;
        while(start < l && idx < n){
            if(arr[idx] - start > mid){
                start += mid;
                ++cnt;
            }
            else{
                start = arr[idx];
                ++idx;
            }
        }
        if(cnt > m) left = mid+1;
        else right = mid;
    }
    printf("%d", left);
}