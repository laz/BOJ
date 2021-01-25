#include <cstdio>
#include <deque>
using namespace std;

int main(){
    int n, m, ans = 0, target, tmp;
    scanf("%d %d", &n, &m);
    deque<int> dq;
    for(int i = n; i >= 1; --i){
        dq.push_front(i);
    }
    for(int i = 1; i <= m; ++i){
        scanf("%d", &target);

        if(dq.front() == target){
            dq.pop_front();
            continue;
        }
        
        int left = 0, right = 1;
        for(auto it = dq.begin(); *it != target; ++it, ++left);
        for(auto it = dq.rbegin(); *it != target; ++it, ++right);
        if(left < right){
            for(int i = 0; i < left; ++i){
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            dq.pop_front();
            ans += left;
        }
        else{
            for(int i = 0; i < right-1; ++i){
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            dq.pop_back();
            ans += right;
        }
            
    }
    printf("%d\n", ans);
}
