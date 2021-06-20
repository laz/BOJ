#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, Hatk, t, a, h;
    long long Hmaxhp = 0, ans = 0;
    cin >> n >> Hatk;
    for(int i = 0; i < n; ++i){
        cin >> t >> a >> h;
        if(t == 1){
            //싸움
            if(h % Hatk == 0) Hmaxhp += a * ((h/Hatk) - 1);
            else Hmaxhp += a * (h/Hatk);
        }
        if(t == 2){
            Hatk += a;
            Hmaxhp -= h;
            if(Hmaxhp < 0) Hmaxhp = 0;
        }
        ans = max(ans, Hmaxhp);
    }
    cout << ans+1;
}