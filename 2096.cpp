#include <iostream>
#include <algorithm>
using namespace std;

int cache[6][2], arr[3];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c; cin >> n;
    for(int i = 0; i < 3; ++i){
        cin >> cache[i][0];
        cache[i+3][0] = cache[i][0];
    }
    for(int i = 1; i < n; ++i){
        cin >> arr[0] >> arr[1] >> arr[2];
        cache[0][i%2] = arr[0] + max(cache[0][(i+1)%2], cache[1][(i+1)%2]);
        cache[1][i%2] = arr[1] + max({cache[0][(i+1)%2], cache[1][(i+1)%2], cache[2][(i+1)%2]});
        cache[2][i%2] = arr[2] + max(cache[1][(i+1)%2], cache[2][(i+1)%2]);
        cache[3][i%2] = arr[0] + min(cache[3][(i+1)%2], cache[4][(i+1)%2]);
        cache[4][i%2] = arr[1] + min({cache[3][(i+1)%2], cache[4][(i+1)%2], cache[5][(i+1)%2]});
        cache[5][i%2] = arr[2] + min(cache[4][(i+1)%2], cache[5][(i+1)%2]);
    }
    cout << max({cache[0][(n+1)%2], cache[1][(n+1)%2], cache[2][(n+1)%2]}) << " " << min({cache[3][(n+1)%2], cache[4][(n+1)%2], cache[5][(n+1)%2]});
}