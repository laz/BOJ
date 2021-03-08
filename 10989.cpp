#include <iostream>
using namespace std;

int b[10001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        b[tmp]++;
    }
    for(int i = 1; i <= 10000; ++i)
        for(int j = 0; j < b[i]; ++j)
            cout << i << "\n";
}