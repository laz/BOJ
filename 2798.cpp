#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100];
int ans = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    vector<int> v(n, 0);
    for(int i = 3; i < n; ++i)
        v[i] = 1;
    
    do{
        int sum = 0;
        for(int i = 0; i < n; ++i)
            if(!v[i]) sum += arr[i];

        if(sum <= m && sum > ans) ans = sum;
        
    }while(next_permutation(v.begin(), v.end()));

    cout << ans;
}