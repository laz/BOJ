#include <cstdio>
#include <vector>
using namespace std;

vector<int> arr(20);
vector<bool> visited(2000001);
int n;

void d(int idx, int sum){
    if(idx == n) {
        visited[sum] = true;
        return ;
    }
    
    d(idx+1, sum);
    d(idx+1, sum + arr[idx]);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    d(0, 0);
    for(int i = 1; i < 2000001; ++i){
        if(visited[i]) continue;
        printf("%d\n", i);
        break;
    }
}