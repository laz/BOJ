#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool check[101];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
}

struct cand{
    int number, likes, time;
    cand(int a, int b, int c) {
        number = a,
        likes = b,
        time = c;
    }
};

bool cmpLikes(const cand& a, const cand& b) {
    if(a.likes != b.likes) return a.likes < b.likes;
    return a.time < b.time;
}

bool cmp(const cand& a, const cand& b) {
    return a.number < b.number;
}

int main() {
    input();
    
    vector<cand> cands;
    int num;
    for(int i = 0; i < m; ++i) {
        cin >> num;

        if(check[num]) {
            // find and increment
            for(cand& c : cands) {
                if(c.number == num) {
                    c.likes++;
                    break;
                }
            }
        } else if(cands.size() < n) {
            check[num] = true;
            cands.push_back(cand(num, 1, i));
        } else {
            sort(cands.begin(), cands.end(), cmpLikes);
            check[cands[0].number] = false;
            check[num] = true;
            cands[0].number = num; cands[0].likes = 1; cands[0].time = i;
        }
    }
    
    sort(cands.begin(), cands.end(), cmp);
    for(int i = 0; i < n; ++i)
        cout << cands[i].number << " ";
}