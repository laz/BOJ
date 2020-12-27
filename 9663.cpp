#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> placed;

bool isValid(int y, int x){
    for(int j = 0; j < placed.size(); ++j){
        if(x == placed[j] || x == placed[j] + (y-j) || x == placed[j] - (y-j)) return false;
    }
    return true;
}

int nQueen(int y){
    if(y == n) return 1;
    int cnt = 0;
    for(int i = 0 ; i < n; ++i){
        if(!isValid(y, i)) continue;
        placed.push_back(i);
        cnt += nQueen(y+1);
        placed.pop_back();
    }
    return cnt;
}

int main(){
    scanf("%d", &n);
    cnt = nQueen(0);
    printf("%d\n", cnt);
}