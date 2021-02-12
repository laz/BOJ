#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 33333333;

vector<pair<int, int> > graph[2001];

void d(vector<int>& dist, int start){
    //w u
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int w = -pq.top().first, u = pq.top().second; pq.pop();
        if(dist[u] < w) continue;
        int len = graph[u].size();
        for(int v = 0; v < len; ++v){
            int nw = w + graph[u][v].second, nv = graph[u][v].first;
            if(dist[nv] <= nw) continue;
            dist[nv] = nw;
            pq.push({-nw, nv});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
        for(auto& v : graph)
            v.clear();
        int n, m, t, s, g, h, a, b, c, distGH;
        cin >> n >> m >> t >> s >> g >> h;
        --s; --g; --h;
        for(int i = 0; i < m; ++i){
            cin >> a >> b >> c; --a; --b;
            if((a == g && b == h) || (a == h && b == g)) distGH = c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        vector<pair<int, int> > targets(t);
        vector<pair<int, int> > check(t);
        for(int i = 0; i < t; ++i){
            cin >> targets[i].first;
            --targets[i].first;
            check[i].first = targets[i].first;
        }
        vector<int> dist(n, INF);
        d(dist, s);
        //s -> t
        for(int i = 0 ; i < t; ++i)
            targets[i].second = dist[targets[i].first];

        //
        int ans1 = dist[g] + distGH;
        int ans2 = dist[h] + distGH;
        fill(dist.begin(), dist.end(), INF);
        d(dist, g);
        for(int i = 0; i < t; ++i){
            check[i].second = ans2 + dist[check[i].first];
        }
        //
        fill(dist.begin(), dist.end(), INF);
        d(dist, h);
        for(int i = 0; i < t; ++i){
            check[i].second = min(check[i].second, ans1 + dist[check[i].first]);
        }
        priority_queue<int> pq;
        for(int i = 0; i < t; ++i){
            if(targets[i].second == check[i].second)
                pq.push(-(targets[i].first+1));
        }
        while(!pq.empty()){
            cout << -pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
    }
}