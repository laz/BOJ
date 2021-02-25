#include <cstdio>
#include <list>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    list<int> l;
    for(int i = 0; i < n; ++i){
        l.push_back(i+1);
    }
    auto it = l.begin();
    printf("<");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k-1; ++j){
            it++;
            if(it == l.end()) it = l.begin();
        }
        printf("%d", *it);
        if(i < n-1) printf(", ");
        it = l.erase(it);
        if(it == l.end()) it = l.begin();
    }
    printf(">");
}