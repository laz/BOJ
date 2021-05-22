#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    int left = 0, right = v[n-1]+1;
    while(left < right){
        int mid = (left + right) / 2;
        int sum = 1, tmp = v[0];
        for(int i = 1; i < n; ++i){
            int gap = v[i] - tmp;
            if(mid <= gap){
                ++sum;
                tmp = v[i];
            }
        }
        if(sum >= c) left = mid+1;
        else right = mid;
    }
    cout << left-1; 
}