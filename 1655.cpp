#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

int median(int n){
    
    if(maxHeap.size() == minHeap.size())
        maxHeap.push(n);
    else
        minHeap.push(n);

    if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
        int a = maxHeap.top();
        int b = minHeap.top();
        maxHeap.pop();
        minHeap.pop();
        maxHeap.push(b);
        minHeap.push(a);
    }

    return maxHeap.top();
}

int main(){
    int n, num;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        printf("%d\n", median(num));
    }
}