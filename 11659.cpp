#include <iostream>
using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> arr[1];
    for(int i = 2; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << "\n";
    }
}
