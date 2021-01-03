#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
    int x, y;
};
int cmpX(const point& a, const point& b){
    return a.x < b.x;
}
int cmpY(const point& a, const point& b){
    return a.y < b.y;
}
int n;

int dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int brute(vector<point>::iterator it, int n){
    int ret = numeric_limits<int>::max();
    for(int i = 0 ; i < n; ++i)
        for(int j = i+1 ; j < n; ++j)
            ret = min(ret, dist(it[i], it[j]));

    return ret;
}

int dac(vector<point>::iterator it, int n){
    //If small enough, bruteforce
    if(n <= 3)
        return brute(it, n);
        
    //Closest pair either in left are or right
    int mid = n/2;
    int midP = (it+mid)->x;
    int minDist = min(dac(it, mid), dac(it + mid, n - mid));

    //Closest pair across the boundary
    vector<point> tmp;
    tmp.reserve(n);
    for(int i = 0; i < n; ++i){
        //Select points within minDist from mid
        int d = it[i].x - midP;
        if(d*d < minDist)
            tmp.push_back(it[i]);
    }
    sort(tmp.begin(), tmp.end(), cmpY);
    int size = tmp.size();
    for(int i = 0; i < size; ++i){
        for(int j = i+1 ; j < size; ++j){
            if((tmp[j].y - tmp[i].y)*(tmp[j].y - tmp[i].y) > minDist)
                break;
            minDist = min(minDist, dist(tmp[i], tmp[j]));
        }   
    }

    return minDist;
}

int main(){
    scanf("%d", &n);
    vector<point> points(n);
    for(int i = 0; i < n; ++i)
        scanf("%d %d", &points[i].x, &points[i].y);

    sort(points.begin(), points.end(), cmpX);
    printf("%d\n", dac(points.begin(), n));
}