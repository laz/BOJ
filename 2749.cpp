#include <cstdio>
#include <vector>
using namespace std;

const int n = 2;
vector<vector <int> > mat;

vector<vector<int> > multiply(vector<vector<int> >& a, vector<vector<int> >& b){

    vector<vector<int> > ret;
    for(int i = 0; i < n; ++i){
        vector<int> tmp;
        for(int j = 0; j < n; ++j){
            long long t = 0;
            for(int k = 0; k < n; ++k)
                t += 1LL * a[i][k] * b[k][j] % 1000000;
            t = t % 1000000;
            tmp.push_back(t);
        }
        ret.push_back(tmp);
    }

    return ret;
}

vector<vector<int> > multiplyN(long long b){
    if(b == 1)
        return mat;
    if(b % 2){
        vector<vector<int> > tmp = multiplyN(b-1);
        return multiply(tmp, mat);
    }

    vector<vector<int> > get = multiplyN(b/2);
    vector<vector<int> > ret = multiply(get, get);

    return ret;
}

int main(){

    vector<int> a = {1, 1};
    vector<int> b = {1, 0};
    mat.push_back(a);
    mat.push_back(b);

    long long nn;
    scanf("%lld", &nn);
    if(nn == 1){
        printf("%d\n", 1);
        return 0;
    }
    vector<vector<int> > res = multiplyN(nn-1);

    printf("%d\n", res[0][0]);
}