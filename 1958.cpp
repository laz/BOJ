#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n1, n2;
int cache[101][101][101];
string s1, s2, s3;

int main(){
    cin >> s1 >> s2 >> s3;
    int i, j, k;
    for(i = 1; i <= s1.size(); ++i){
        for(j = 1; j <= s2.size(); ++j){
            for(k = 1; k <= s3.size(); ++k){
                if((s1[i-1] == s2[j-1]) && (s2[j-1] == s3[k-1]))
                    cache[i][j][k] = cache[i-1][j-1][k-1] + 1;
                else
                    cache[i][j][k] = max({cache[i-1][j][k], cache[i][j-1][k], cache[i][j][k-1]});
            }
        }
    }
    cout << cache[i-1][j-1][k-1] << endl;
}