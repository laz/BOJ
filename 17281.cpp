#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int order[9];
int arr[50][9];
int n, ans = 0;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
        }
    }
}

void hit(int num, int& score, list<int>& base) {

    if(num == 4) {
        score += base.size()+1;
        base.clear();
        return ;
    }
    
    for(auto it = base.begin(); it != base.end();) {
        if((*it) + num >= 4) {
            it = base.erase(it);
            score++;
        } else {
            (*it) += num;
            ++it;
        }
    }
    base.push_back(num);
}

void play() {
    
    list<int> base;
    int score = 0, out = 0, turn = 0;
    
    for(int i = 0; i < n; ++i) {
        while(out < 3) {
            while(1) {
                if(arr[i][order[turn]]) hit(arr[i][order[turn]], score, base);
                else out++;

                turn++;
                if(turn == 9) turn = 0;

                if(out >= 3) break;
            }
        }
        // 이닝 끝
        base.clear();
        out = 0;
    }
    ans = max(ans, score);
}

void d(int idx, int visited) {
    if(idx == 9 ) {
        play();
        return ;
    }
    for(int i = 0; i < 9; ++i) {
        if(visited & (1 << i)) continue;
        order[idx] = i;
        if(idx+1 == 3) d(idx+2, visited | (1 << i));
        else d(idx+1, visited | (1 << i));
    }
}

int main() {
    input();
    
    order[3] = 0;
    d(0, 1);
    cout << ans;
}