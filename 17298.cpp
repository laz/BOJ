#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n, read, tmp;
    scanf("%d", &n);
    stack<int> nge;
    stack<int> print;
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        scanf("%d", &read);
        while(!nge.empty() && nge.top() < read){
            if(ans.back() != -1){
                print.push(ans.back());
                ans.pop_back();
                continue;
            }
            else
                print.push(read);
            ans.pop_back();
            nge.pop();
        }
        while(!print.empty()){
            tmp = print.top();
            ans.push_back(tmp);
            print.pop();
        }
        nge.push(read);
        ans.push_back(-1);
    }
    for(auto e : ans)
        printf("%d ", e);
    printf("\n");
}