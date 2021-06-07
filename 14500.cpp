#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<vector<vector<bool> > > tetrominos;
int arr[505][505];
int n, m;

void input() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
}

// vertical symmetry
vector<vector<bool> > symmetry(vector<vector<bool> >& v) {
    int x = v.size(), y = v[0].size();
    vector<vector<bool> > ret(x, vector<bool>(y));
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            ret[i][j] = v[i][y-1-j];
        }
    }
    return ret;
}

// clockwise 90
vector<vector<bool> > spin(vector<vector<bool> >& v) {
    int x = v.size(), y = v[0].size();
    vector<vector<bool> > ret(y, vector<bool>(x));
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            ret[j][x-1-i] = v[i][j];
        }
    }
    return ret;
}

void makeTetros() {
    // I
    vector<vector<bool> > v(1, vector<bool>(4));
    for(int i = 0; i < 4; ++i) {
        v[0][i] = true;
    }
    tetrominos.push_back(v);
    // 1 spin
    tetrominos.push_back(spin(v));

    // ㅁ
    vector<vector<bool> > vv(2, vector<bool>(2));
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            vv[i][j] = true;
        }
    }
    tetrominos.push_back(vv);

    // L
    vector<vector<bool> > vvv(3, vector<bool>(2));
    for(int i = 0; i < 3; ++i) {
        vvv[i][0] = true;
    }
    vvv[2][1] = true;
    tetrominos.push_back(vvv);
    auto vvvSymmetry = symmetry(vvv);
    tetrominos.push_back(vvvSymmetry);

    // 3 spins with symmetry
    for(int i = 0; i < 3; ++i) {
        vvv = spin(vvv);
        vvvSymmetry = spin(vvvSymmetry);
        tetrominos.push_back(vvv);
        tetrominos.push_back(vvvSymmetry);
    }

    // ㅗ
    vector<vector<bool> > vvvv(2, vector<bool>(3));
    vvvv[0][1] = true;
    for(int i = 0; i < 3; ++i) {
        vvvv[1][i] = true;
    }
    // 3 spins
    tetrominos.push_back(vvvv);
    for(int i = 0; i < 3; ++i) {
        vvvv = spin(vvvv);
        tetrominos.push_back(vvvv);
    }

    // ㄹ
    vector<vector<bool> > vvvvv(3, vector<bool>(2));
    vvvvv[0][0] = vvvvv[1][0] = vvvvv[1][1] = vvvvv[2][1] = true;
    // 1 spin with symmetry
    tetrominos.push_back(vvvvv);
    auto vvvvvSymmetry = symmetry(vvvvv);
    tetrominos.push_back(vvvvvSymmetry);
    tetrominos.push_back(spin(vvvvv));
    tetrominos.push_back(spin(vvvvvSymmetry));
}

int bf() {
    int ret = 0;

    for(auto tetromino : tetrominos) {
        int x = tetromino.size(), y = tetromino[0].size();

        for(int i = 0; i <= n-x; ++i) {
            for(int j = 0; j <= m-y; ++j) {
                // left top
                int sum = 0;
                for(int k = 0; k < x; ++k) {
                    for(int l = 0; l < y; ++l) {
                        if(tetromino[k][l]) 
                            sum += arr[i+k][j+l];
                    }
                }
                ret = max(ret, sum);
            }
        }
    }
    return ret;
}

int main() {
    input();

    makeTetros();
    cout << bf();
}