#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[100002];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    memset(map, -1, sizeof(map));
    queue<int> que;
    map[n] = 0;
    que.push(n);
    while(map[k] == -1){
        int curr = que.front(); que.pop();
        for(int next : {curr-1, curr+1, curr*2}){
            if(next < 0 || next > 100000) continue;
            if(map[next] != -1) continue;
            map[next] = map[curr] + 1;
            que.push(next);
        }
    }
    printf("%d\n", map[k]);
}