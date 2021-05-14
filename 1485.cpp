#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct point{
    int x, y;
};

point points[4];
int d[4][4];

int cmp(const point& a, const point& b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int dist(const point& a, const point& b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main(){
    int t, square, len;
    scanf("%d", &t);
    while(t--){
        square = true;
        for(int i = 0; i < 4; ++i)
            scanf("%d %d", &points[i].x, &points[i].y);
        sort(points, points+4, cmp);

        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(i != j)
                    d[i][j] = dist(points[i], points[j]);
            }
        }

        if(d[0][1] == d[0][2] && d[3][1] == d[3][2] && d[0][3] == d[1][2]) 
            printf("1\n");
        else
            printf("0\n");
    }
}