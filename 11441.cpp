#include <iostream>
using namespace std;

int arr[100001];
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] = arr[i] + arr[i-1];
    }
    int i, j;
    cin >> m;
    while(m--){
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << "\n";
    }
}