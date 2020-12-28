#include <bits/stdc++.h>
using namespace std;

const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();

int n, op;
int num[11];
vector<int> operators;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    for(int i = 0; i < 4; ++i){
        scanf("%d", &op);
        for(int j = 0; j < op; ++j){
            operators.push_back(i);
        }
    }
    int mn = MAX;
    int mx = MIN;
    do{
        int ret = num[0];
        for(int i = 0; i < operators.size(); ++i){
            if(operators[i]==0) ret += num[i+1];
            else if(operators[i]==1) ret -= num[i+1];
            else if(operators[i]==2) ret *= num[i+1];
            else if(operators[i]==3) ret /= num[i+1];
        }
        mn = min(mn, ret);
        mx = max(mx, ret);
    } while(next_permutation(operators.begin(), operators.end()));
    printf("%d %d\n", mx, mn);
}