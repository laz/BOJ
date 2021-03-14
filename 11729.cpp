#include <iostream>
using namespace std;

void moveN(int from, int to, int tmp, int n){
    if(n == 1){
        cout << from << " " << to << "\n";
        return ;
    }
    moveN(from, tmp, to, n-1);
    moveN(from, to, tmp, 1);
    moveN(tmp, to, from, n-1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, rep = 1;
    cin >> n;
    for(int i = 0; i < n; ++i) rep *= 2;
    cout << rep-1 << "\n";
    moveN(1, 3, 2, n);
}