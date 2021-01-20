#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    queue<int> que;
    for(int i = 1; i <= n; ++i){
        que.push(i);
    }
    for(int i = 0 ; i < n-1; ++i){
        que.pop();
        int tmp = que.front();
        que.pop();
        que.push(tmp);
    }
    printf("%d\n", que.front());
}