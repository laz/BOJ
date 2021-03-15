#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tab[100], cnt[100];
int n;

bool exist(int item){
    for(int i = 0; i < n; ++i)
        if(tab[i] == item) return true;
    
    return false;
}

int main(){
    int k;
    cin >> n >> k;
    vector<int> v(k);
    for(int i = 0; i < k; ++i)
        cin >> v[i];

    // 처음 꽂기
    int idx, c;
    for(idx = 0, c = 0; c < n; ++idx){
        if(exist(v[idx])) continue;
        tab[c] = v[idx];
        c++;
    }

    // 남은 얘들 횟수
    for(int i = idx; i < k; ++i)
        cnt[v[i]]++;
    
    int ans = 0;
    for(int i = idx; i < k; ++i){
        if(exist(v[i])) {
            cnt[v[i]]--;
            continue;
        }
        
        ans++;
        if(i == k-1) break;
        
        // 다시 안쓰이는 녀석 있으면 제거
        bool done = false;
        for(int j = 0; j < n; ++j){
            if(cnt[tab[j]] == 0){
                tab[j] = v[i];
                cnt[v[i]]--;
                done = true;
                break;
            }
        }
        if(done) continue;

        // 가장 늦게 다시 쓰이는 녀석 제거
        vector<pair<int, int> > arr(n); //index value
        for(int j = 0; j < n; ++j) {
            arr[j].first = j;
            arr[j].second = tab[j];
        }
        for(int j = i + 1; arr.size() > 1; ++j){
            for(auto it = arr.begin(); it != arr.end(); ++it){
                if((*it).second == v[j]) {
                    arr.erase(it);
                    break;
                }
            }
        }
        tab[arr[0].first] = v[i];
        cnt[v[i]]--;
    }
    
    cout << ans << endl;
    
}