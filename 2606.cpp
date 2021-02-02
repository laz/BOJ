#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > map;
vector<bool> visited;

int virus(int from){
    int ret = 1;
    visited[from] = true;

    for(int to : map[from]){
        if(visited[to]) continue;
        ret += virus(to);
    }
    return ret;
}

int main(){
    int c, n;
    scanf("%d %d", &c, &n);
    vector<int> tmp;
    visited = vector<bool>(c, false); 
    for(int i = 0; i < c; ++i)
        map.push_back(tmp);
    int x, y;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &x, &y);
        map[x-1].push_back(y-1);
        map[y-1].push_back(x-1);
    }
    printf("%d\n", virus(0)-1);
}