#include <bits/stdc++.h>
using namespace std;

int n, blue, white;
int quad[128][128];

int quadtree(int topleftY, int topleftX, int bottomRightY, int bottomRightX){
    //더이상 쪼갤 수 없으면 increment and return 색
    if((topleftY == bottomRightY) && (topleftX == bottomRightX)){
        quad[topleftY][topleftX] == 0 ? white++ : blue++;
        return quad[topleftY][topleftX];
    }

    int midX = (topleftX + bottomRightX) / 2;
    int midY = (topleftY + bottomRightY) / 2;
    //4개로 쪼개서 quadtree
    int p1 = quadtree(topleftY, topleftX, midY, midX);
    int p2 = quadtree(topleftY, midX+1, midY, bottomRightX);
    int p3 = quadtree(midY+1, topleftX, bottomRightY, midX);
    int p4 = quadtree(midY+1, midX+1, bottomRightY, bottomRightX);

    //4개 쪼개서 보낸게 다 같으면 색-3, return 색
    if((p1 == p2) && (p2 == p3) && (p3 == p4) && (p1 != -1)){
        p1 == 0 ? white -= 3 : blue -= 3;
        return p1;
    }
        
    //다 같지 않으면 return -1
    return -1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i){
        for(int j = 0 ; j < n; ++j){
            scanf("%d", &quad[i][j]);
        }
    }
    quadtree(0, 0, n-1, n-1);
    printf("%d\n%d\n", white, blue);
}