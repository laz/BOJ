#include <iostream>
#include <string>
using namespace std;

string map[1001];
int js[1001][1001], is[1001][1001], os[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> map[i];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            js[i][j] = (map[i][j-1] == 'J' ? 1 : 0) + js[i-1][j] + js[i][j-1] - js[i-1][j-1];
            is[i][j] = (map[i][j-1] == 'I' ? 1 : 0) + is[i-1][j] + is[i][j-1] - is[i-1][j-1];
            os[i][j] = (map[i][j-1] == 'O' ? 1 : 0) + os[i-1][j] + os[i][j-1] - os[i-1][j-1];
        }
    }

    int a, b, c, d;
    while(k--){
        cin >> a >> b >> c >> d;
        cout << js[c][d] - js[a-1][d] - js[c][b-1] + js[a-1][b-1] << " " 
        << os[c][d] - os[a-1][d] - os[c][b-1] + os[a-1][b-1] << " "
        << is[c][d] - is[a-1][d] - is[c][b-1] + is[a-1][b-1] << "\n";
    }
}
