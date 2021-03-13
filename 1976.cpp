#include <iostream>
using namespace std;

int map[200][200], arr[1000];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> map[i][j];

    for(int i = 0; i < n; ++i)
        map[i][i] = 1;
    
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(map[i][k] && map[k][j]) map[i][j] = map[j][i] = 1;

    for(int i = 0; i < m; ++i)
        cin >> arr[i];

    for(int i = 0; i < m-1; ++i){
        if(!map[arr[i]-1][arr[i+1]-1]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    
}