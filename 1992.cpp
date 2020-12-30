#include <bits/stdc++.h>
using namespace std;

int n;
string quad[64];
string ans;

int compress(int tly, int tlx, int bry, int brx){
    
    if((tly == bry) && (tlx == brx)){
        ans.push_back(static_cast<char>(quad[tly][tlx]));
        return quad[tly][tlx];
    }

    ans.push_back('(');
    int midX = (tlx + brx) / 2;
    int midY = (tly + bry) / 2;

    int p1 = compress(tly, tlx, midY, midX);
    int p2 = compress(tly, midX+1, midY, brx);
    int p3 = compress(midY+1, tlx, bry, midX);
    int p4 = compress(midY+1, midX+1, bry, brx);
    
    if((p1 == p2) && (p2 == p3) && (p3 == p4) && (p1 != -1)){
        for(int i = 0; i < 5; ++i)
            ans.pop_back();
        ans.push_back(static_cast<char>(p1));
        return p1;
    }
    ans.push_back(')');
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; ++i){
        cin >> quad[i];
    }
    ans.reserve(5000);
    compress(0, 0, n-1, n-1);
    cout << ans << "\n";
}