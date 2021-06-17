#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[100007];
int n, m;

void input() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cin >> m;
}

int init(vector<int>& tree, int i = 1, int s = 0, int e = n-1) {
    if(s == e) return tree[i] = s;
    int m = (s + e) >> 1;
    int left = init(tree, i<<1, s, m);
    int right = init(tree, i<<1|1, m+1, e);
    if(arr[left] == arr[right]) return tree[i] = min(left, right);
    return tree[i] = arr[left] < arr[right] ? left : right;
}

int query(vector<int>& tree, int l, int r, int i = 1, int s = 0, int e = n-1) {
    if(l > e || r < s) return n;
    if(l <= s && e <= r) return tree[i];
    int m = (s + e) >> 1;
    int left = query(tree, l, r, i<<1, s, m);
    int right = query(tree, l, r, i<<1|1, m+1, e);
    if(arr[left] == arr[right]) return min(left, right);
    return arr[left] < arr[right] ? left : right;
}

int update(vector<int>& tree, int t, int v, int i = 1, int s = 0, int e = n-1) {
    if(t < s || t > e) return tree[i];
    if(s == e) return tree[i] = s;
    int m = (s + e) >> 1;
    int left = update(tree, t, v, i<<1, s, m);
    int right = update(tree, t, v, i<<1|1, m+1, e);
    if(arr[left] == arr[right]) return tree[i] = min(left, right);
    return tree[i] = arr[left] < arr[right] ? left : right;
}

int main() {
    input();
    int h = (int)ceil(log2(n));
    vector<int> tree((1 << (h+1)));
    arr[n] = 2e9;
    init(tree);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            arr[b-1] = c;
            update(tree, b-1, c);
        }
        else cout << query(tree, b-1, c-1)+1 << '\n';
    }
}