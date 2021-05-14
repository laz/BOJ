#include <iostream>
#include <vector>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m, left = 1, right = 2*1e9+1;
    cin >> n >> m;
    vector<int> woods(n);
    for(int i = 0; i < n; ++i)
        cin >> woods[i];
    while(left < right){
        int mid = (1LL * left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < n; ++i)
            if(woods[i] > mid) sum += woods[i] - mid;
        if(sum >= m)
            left = mid+1;
        else
            right = mid;
    }
    cout << left-1;
}