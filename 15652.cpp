#include <bits/stdc++.h>
using namespace std;

int N, M;

void printPermutations(vector<int>& p, int length){
    if(length == M){
        for(int i = 0; i < p.size(); ++i)
            printf("%d ", p[i]+1);
        printf("\n");
        return ;
    }
    for(int i = 0; i < N; ++i){
        if(!p.empty() && i < p.back()) continue;
        p.push_back(i);
        printPermutations(p, length+1);
        p.pop_back();
    }
}

int main(){
    scanf("%d %d", &N, &M);
    vector<int> p;
    printPermutations(p, 0);
}