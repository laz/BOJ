#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, v; cin >> n;
        vector<int> arr(n+1, 0);
        vector<bool> visited(n+1, false);
        for(int i = 1; i <= n; ++i)
            cin >> arr[i];
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            v = arr[i];
            while(v != i){
                visited[v] = true;
                v = arr[v];
            }
            cnt++;
        }
        cout << cnt << "\n";
    }
}