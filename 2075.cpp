#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[3000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0x80, sizeof(arr));
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> arr[j];
        sort(arr, arr+(n*2));
    }
    cout << arr[n];
}