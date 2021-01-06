#include <iostream>
#include <cstring>
using namespace std;

struct mat{
    int row, column;
};

int cache[501][501];
mat m[501];

int min(int a, int b) { return a > b ? b : a;}
int findMin(int m1, int m2){
    
    if(m1 == m2) return 0;

    int& ret = cache[m1][m2];
    if(ret != -1) return ret;

    ret = __INT_MAX__;
    for(int i = m1; i < m2; ++i)
        ret = min(ret, findMin(m1, i) + findMin(i+1, m2) + m[m1].row * m[i].column * m[m2].column);

    return ret;
}

int main(){
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> m[i].row >> m[i].column;
    memset(cache, -1, sizeof(cache));
    cout << findMin(0, n-1) << '\n';

}