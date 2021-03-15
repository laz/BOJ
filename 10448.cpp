#include <cstdio>
using namespace std;

int tri[45];
bool arr[1001];

int main(){
    for(int i = 1; i < 45; ++i) {
        tri[i] = i * (i+1) / 2;
    }

    for(int i = 1; i < 45; ++i){
        for(int j = 1; j < 45; ++j){
            for(int k = 1; k < 45; ++k){
                int n = tri[i] + tri[j] + tri[k];
                if(n > 1000) break;
                arr[n] = true;
            }
        }
    }
    
    int t, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &k);
        printf("%d\n", arr[k] ? 1 : 0);
    }
}