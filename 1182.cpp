#include <iostream>
#include <vector>
using namespace std;

int arr[20];
int n, s, cnt = 0;

void d(int idx, int sum){
    sum += arr[idx];
    if(n == idx) return ;
    if(sum == s) cnt++;

    d(idx+1, sum);
    d(idx+1, sum - arr[idx]);
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    d(0, 0);
    cout << cnt;
}