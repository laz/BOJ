#include <iostream>
using namespace std;

int arr[1025][1025];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> arr[i][j];
   
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int a, b, c, d;
    while(m--){
        cin >> a >> b >> c >> d;
        cout << arr[c][d] - arr[c][b-1] - arr[a-1][d] + arr[a-1][b-1] << "\n";
    }
}