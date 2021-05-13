#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
    int a, b, c, d;
} points[100000];

int cmpA(const point& a, const point& b){
    return a.a < b.a;
}
int cmpB(const point& a, const point& b){
    return a.b < b.b;
}
int cmpC(const point& a, const point& b){
    return a.c < b.c;
}

int parent[100000];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b, c; cin >> a >> b >> c;
        points[i].a = a; points[i].b = b; points[i].c = c; points[i].d = i;
    }
    vector<point> v; v.reserve(3*(n-1));
    sort(points, points + n, cmpA);
    for(int i = 0; i < n-1; ++i){
        point p;
        p.a = points[i].d; p.b = points[i+1].d;
        p.c = min({abs(points[i].a - points[i+1].a), abs(points[i].b - points[i+1].b), abs(points[i].c - points[i+1].c)});
        v.push_back(p);
    }
    sort(points, points + n, cmpB);
    for(int i = 0; i < n-1; ++i){
        point p;
        p.a = points[i].d; p.b = points[i+1].d;
        p.c = min({abs(points[i].a - points[i+1].a), abs(points[i].b - points[i+1].b), abs(points[i].c - points[i+1].c)});
        v.push_back(p);
    }
    sort(points, points + n, cmpC);
    for(int i = 0; i < n-1; ++i){
        point p;
        p.a = points[i].d; p.b = points[i+1].d;
        p.c = min({abs(points[i].a - points[i+1].a), abs(points[i].b - points[i+1].b), abs(points[i].c - points[i+1].c)});
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmpC);
    
    for(int i = 0; i < n; ++i) parent[i] = i;

    int size = v.size(), ans = 0;
    for(int i = 0; i < size; ++i){
        int u = find(v[i].a), vv = find(v[i].b);
        if(u == vv) continue;
        parent[u] = vv;
        ans += v[i].c;
    }
    cout << ans;
}