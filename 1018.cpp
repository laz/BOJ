#include <cstdio>
using namespace std;

int min(int a, int b){ return a > b ? b : a; }

int N, M;
char ch;
bool board[50][50];

int count(int y, int x){
    int whiteStart = 0;
    bool white = true;
    for(int i = y; i < y+8; ++i){
        for(int j = x; j < x+8; ++j){
            if(white != board[i][j]) whiteStart++;
            white = !white;
        }
        white = !white;
    }
    return min(whiteStart, 64-whiteStart);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        getchar();
        for(int j = 0; j < M; ++j){
            scanf("%c", &ch);
            if(ch == 'W') board[i][j] = true;
        }
    }
    int ret = 33;
    for(int i = 0; i < N-7; ++i)
        for(int j = 0; j < M-7; ++j)
            ret = min(ret, count(i, j));
        
    printf("%d\n", ret);
}