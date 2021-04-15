#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > map;
int parent[1000];

int cmp(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b){
    return a.first > b.first;
}

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return ;
    parent[u] = v;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int p, w, src, dst, a, b, c;
    cin >> p >> w >> src >> dst;
    for(int i = 0; i < p; ++i) parent[i] = i;
    map.reserve(p);
    for(int i = 0; i < w; ++i){
        cin >> a >> b >> c;
        map.push_back({c, {a, b}});
    }
    sort(map.begin(), map.end(), cmp);

    for(auto p : map){
        merge(p.second.first, p.second.second);
        if(find(src) == find(dst)){
            cout << p.first;
            return 0;
        }
    }


}