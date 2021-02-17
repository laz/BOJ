#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp, sum = 0;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        pq.push(-tmp);
    }
    for(int i = 0; i < n-1; ++i){
        int x = -pq.top(); pq.pop();
        int y = -pq.top(); pq.pop();
        sum += x + y;
        pq.push(-(x+y));
    }
    cout << sum << endl;
}