#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[101];
vector<int> rev;
vector<long long> money;
bool reachable[101][101];
int n, src, dst;

bool bf(){
    money = vector<long long>(n+1, -1e18);
    money[src] = rev[src];
    for(int i = 0; i < n; ++i){
        for(int from = 0; from < n; ++from){
            for(auto p : adj[from]){
                int to = p.first, dist = p.second;
                money[to] = max(money[to], money[from] + dist);
            }
        }
    }
    for(int from = 0; from < n; ++from){
        for(auto p : adj[from]){
            int to = p.first, dist = p.second;
            if(money[to] < money[from] + dist && reachable[src][from] && reachable[from][dst]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m, a, b, c;
    cin >> n >> src >> dst >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, -c});
    }
    rev = vector<int>(n+1);
    for(int i = 0; i < n; ++i){
        cin >> rev[i];
    }
    for(int i = 0; i < n; ++i){
        for(auto& p : adj[i]){
            p.second += rev[p.first];
        }
    }
    //reachable
    for(int from = 0; from < n; ++from){
        reachable[from][from] = 1;
        queue<int> q;
        q.push(from);
        while(!q.empty()){
            int curr = q.front(); q.pop();
            for(auto p : adj[curr]){
                int to = p.first;
                if(reachable[from][to]) continue;
                reachable[from][to] = 1;
                q.push(to);
            }
        } 
    }
    if(!reachable[src][dst]) cout << "gg\n";
    else if(bf()) cout << "Gee";
    else cout << money[dst];
}