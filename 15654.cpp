#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[9];
int arr[9];
int n, m;

void d(int mm, vector<int>& v){
    if(mm == m) {
        for(auto vv : v) 
            cout << vv << " ";
        cout << "\n";
        return ;
    }

    for(int i = 1; i <= n; ++i){
        if(visited[i]) continue;
        v[mm] = arr[i];
        visited[i] = true;
        d(mm+1, v);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    sort(arr+1, arr+n+1);
    vector<int> v(m, 0);
    d(0, v);
}