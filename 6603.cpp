#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        vector<int> v;
        for(int i = 0; i < n; ++i){
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        vector<int> vv(n, 0);
        for(int i = 6; i < n; ++i){
            vv[i] = 1;
        }
        do{
            for(int i = 0; i < v.size(); ++i){
                if(!vv[i]) printf("%d ", v[i]);
            }
            printf("\n");
        }while(next_permutation(vv.begin(), vv.end()));
        printf("\n");
    }
    
}