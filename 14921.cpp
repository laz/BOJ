#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    int s = 0, e = n-1, ans = 2e9+1, absAns;
    while(s < e){
        int sum = arr[s] + arr[e];
        if(abs(sum) < ans) {
            ans = abs(sum);
            absAns = sum;
        }
        if(sum <= 0) s++;
        else e--;
    }
    cout << absAns;
}