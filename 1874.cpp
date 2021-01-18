#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int seq[100001];

int main(){
    int n, cnt = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &seq[i]);
    
    string ans;
    stack<int> s;

    for(int i = 0 ; i < n; ++i){
        while(s.empty() || s.top() < seq[i]){
            s.push(cnt++);
            ans.push_back('+');
        }
        if(s.top() != seq[i]){
            printf("NO\n");
            return 0;
        }
        s.pop();
        ans.push_back('-');
    }

    for(int i = 0; i < ans.size(); ++i)
        printf("%c\n", ans[i]);
}
