#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int k, n, sum = 0;
    scanf("%d", &k);
    stack<int> jammin;
    while(k--){
        scanf("%d", &n);
        if(!n) {
            sum -= jammin.top();
            jammin.pop();
        }
        else {
            sum += n;
            jammin.push(n);
        }
    }
    printf("%d\n", sum);
}