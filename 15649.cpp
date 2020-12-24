#include <bits/stdc++.h>
using namespace std;

int N, M;

void printPermutations(vector<int>& p, vector<bool> done, int length){
    if(length == M){
        for(int i = 0; i < p.size(); ++i)
            printf("%d ", p[i]+1);
        printf("\n");
        return ;
    }
    for(int i = 0; i < N; ++i){
        if(done[i]) continue;
        p.push_back(i);
        done[i] = true;
        printPermutations(p, done, length+1);
        p.pop_back();
        done[i] = false;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    vector<int> p;
    vector<bool> done;
    for(int i = 0; i < N; ++i) done.push_back(false);
    printPermutations(p, done, 0);
}