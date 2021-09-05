#include <bits/stdc++.h>
using namespace std;

int arr[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            arr[i][j] = 333333333;
        }
    }
    
    for(vector<int> fare : fares) {
        arr[fare[0]][fare[1]] = fare[2];
        arr[fare[1]][fare[0]] = fare[2];
    }

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n ;++j) {
                if(i == j) arr[i][i] = 0;
                if(arr[i][k] && arr[k][j]) arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    answer = arr[s][a] + arr[s][b];
    for(int i = 1; i <= n; ++i) {
        int cost = arr[s][i] + arr[i][a] + arr[i][b];
        answer = min(answer, cost);
    }
    return answer;
}