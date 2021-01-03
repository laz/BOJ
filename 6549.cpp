#include <cstdio>
using namespace std;

int hist[100002];

long long max(long long a, long long b) {return a > b ? a : b;}
long long min(long long a, long long b) {return a < b ? a : b;}
long long dac(int lo, int hi){
    //Base 
    if(lo == hi)
        return hist[lo];

    //Divide
    int mid = (lo + hi) / 2;
    
    //둘 중 max
    long long ret = max(dac(lo, mid), dac(mid+1, hi));
    
    //경계를 포함한 경우
    int left = mid, right = mid + 1;
    long long lowest = min(hist[left], hist[right]);
    ret = max(ret, lowest * 2);
    while(left > lo || right < hi){
        if(left > lo && (right >= hi || hist[left-1] > hist[right+1]))
            lowest = min(lowest, hist[--left]);
        else
            lowest = min(lowest, hist[++right]);

        ret = max(ret, 1LL * (right - left + 1) * lowest);
    }
    return ret;
}

int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(!n)
            return 0;
        for(int i = 0; i < n; ++i)
            scanf("%d", &hist[i]);
            
        printf("%lld\n", dac(0, n-1));
        for(int i = 0; i < 100002; ++i)
            hist[i] = 0;
    }
}