#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > vvi;
const int MOD = 1e9+7;

vvi mat;

vvi multiply(const vvi& a, const vvi& b){
    vvi ret;
    for(int i = 0; i < 2; ++i){
        vector<int> tmp;
        for(int j = 0; j < 2; ++j){
            int t = 0;
            for(int k = 0; k < 2; ++k)
                t += 1LL * a[i][k] * b[k][j] % MOD;
            tmp.push_back(t % MOD);
        }
        ret.push_back(tmp);
    }
    return ret;
}

vvi fib(ll n){
    if(n == 1) return mat;
    if(n%2) return multiply(mat, fib(n-1));
    vvi n2 = fib(n/2);
    return multiply(n2, n2);
}

int main(){
    ll n;
    scanf("%lld", &n);
    if(n == 1){
        printf("1\n");
        return 0;
    }
    vector<int> a{1, 1};
    vector<int> b{1, 0};
    mat.push_back(a);
    mat.push_back(b);

    printf("%d\n", fib(n-1)[0][0]);
}