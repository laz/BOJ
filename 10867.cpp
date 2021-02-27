#include <iostream>
using namespace std;

int arr[2002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        arr[tmp+1000]++;
    }
    for(int i = 0; i < 2002; ++i){
        if(arr[i]) cout << i-1000 << " ";
    }
}