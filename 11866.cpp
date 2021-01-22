#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> que;
    for(int i = 1; i <= n; ++i)
        que.push(i);
    
    printf("<");
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < k-1; ++j){
            int tmp = que.front();
            que.pop();
            que.push(tmp);
        }
        printf("%d, ", que.front());
        que.pop();
    }
    printf("%d>\n", que.front());
}