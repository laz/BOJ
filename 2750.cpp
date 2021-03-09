#include <cstdio>

int arr[1000];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i)
        scanf("%d", &arr[i]);
     
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[i] < arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
}