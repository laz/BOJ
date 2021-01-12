#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct meeting{
    int start, end;
};

int cmp(const meeting& a, const meeting& b){
    if(a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main(){
    int n, s, e;
    scanf("%d", &n);
    meeting* meetings = (meeting*)malloc(sizeof(meeting) * n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &s, &e);
        meetings[i].start = s;
        meetings[i].end = e;
    }
    sort(meetings, meetings+n, cmp);
    int earliest = 0, prevS = 0, cnt = 0;
    for(int i = 0; i < n; ++i){
        if(earliest <= meetings[i].start){
            earliest = meetings[i].end;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}