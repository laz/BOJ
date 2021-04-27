#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[1000000];
vector<int> comp;
int n;

void input() {
    fastio;
    cin >> n;
    comp.reserve(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        comp.push_back(arr[i]);
    }
}

int main() {
    input();

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int i = 0; i < n ;++i) { 
        cout << lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() << " ";
    }
}