#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heap;

void push_heap(int n){
    heap.push_back(n);
    int idx = heap.size()-1;
    while(idx > 0 && heap[(idx-1)/2] < heap[idx]){
        swap(heap[(idx-1)/2], heap[idx]);
        idx = (idx-1)/2;
    }
}

int pop_heap(){
    if(heap.size() == 0) return 0;
    int ret = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    int here = 0;
    while(1){
        int left = here*2+1, right = here*2+2;
        if(left >= heap.size()) break;

        int next = here;
        if(heap[left] > heap[next]) next = left;
        if(right < heap.size() && heap[right] > heap[next]) next = right;

        if(next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
    return ret;
}

int main(){
    int n, op;
    scanf("%d", &n);
    heap.reserve(n);
    while(n--){
        scanf("%d", &op);
        if(op)
            push_heap(op);
        else
            printf("%d\n", pop_heap());
    }
}
