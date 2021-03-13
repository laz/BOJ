#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    ll left = 0, right = 1e18;
    while(left < right){
        ll mid = (left + right) / 2;

        ll t = 0;
        for(int i = 0; i < n; ++i){
            t += mid / v[i];
            if(t > 1e18) break;
        }
        
        if(t >= m) right = mid;
        else left = mid+1;
    }

    cout << left;
}