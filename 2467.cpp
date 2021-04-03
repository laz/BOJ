#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    
    int s = 0, e = n-1, msum = 2e9+1, dragon, ack, best = 2e9+1;
    while(1){
        int sum = arr[s] + arr[e];
        if(abs(sum) < best){
            dragon = arr[s]; ack = arr[e];
            best = abs(sum);
        }
        if(sum <= 0) s++;
        else e--;
        if(s >= e) break;
        
    }
    cout << dragon << " " << ack;
}