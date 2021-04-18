#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m;
char arr[15], save[15];

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) cin >> arr[i];
}

bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u') return true;
    return false;
}

void d(int idx, int cnt, bool vowel, int consonant) {
    if(cnt == n) {
        if(vowel && consonant > 1) {
            for(int i = 0; i < n; ++i) 
                cout << save[i]; 
            cout << "\n";
        }
        return ;
    }

    for(int i = idx; i < m; ++i) {
        save[cnt] = arr[i];
        bool v = isVowel(arr[i]);
        d(i+1, cnt+1, vowel ? vowel : v, v ? consonant : consonant+1);
    }
}

int main() {
    input();
    sort(arr, arr+m);
    d(0, 0, false, 0);
}