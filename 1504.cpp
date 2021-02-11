#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 987654321;

//v w
vector<pair<int, int> > graph[801];
void d(vector<int>& dist, int start){
    //w v
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int u = pq.top().second, w = -pq.top().first; pq.pop();
        if(dist[u] < w) continue;
        int len = graph[u].size();
        for(int v = 0; v < len; ++v){
            int nv = graph[u][v].first, nw = w + graph[u][v].second;
            if(dist[nv] <= nw) continue;
            dist[nv] = nw;
            pq.push({-nw, nv});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, e, a, b, c, v1, v2;
    cin >> n >> e;
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c; --a; --b;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2; --v1; --v2;

    //
    vector<int> dist(n, INF);
    d(dist, 0);
    long long ans1 = dist[v1];
    long long ans2 = dist[v2];
    //
    fill(dist.begin(), dist.end(), INF);
    d(dist, v1);
    ans1 += dist[v2];
    ans2 += dist[n-1];
    //
    fill(dist.begin(), dist.end(), INF);
    d(dist, v2);
    ans1 += dist[n-1];
    ans2 += dist[v1];
    if(ans1 >= INF) cout << -1;
    else cout << min(ans1, ans2);

}

//이거 큐 안쓰고 하면?