#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, tmp;
        scanf("%d %d", &n, &m);
        queue<pair<int, int> > que; //priority, index
        vector<int> priority;
        for(int i = 0; i < n; ++i){
            scanf("%d", &tmp);
            que.push(make_pair(tmp, i));
            priority.push_back(tmp);
        }
        sort(priority.begin(), priority.end());
        int cnt = 1;
        while(1){
            if(que.front().first == priority.back()){
                if(que.front().second == m)
                    break;
                que.pop();
                priority.pop_back();
                cnt++;
            }
            else{
                pair<int, int> p = que.front();
                que.pop();
                que.push(p);
            }
        }
        printf("%d\n", cnt);
    }
}