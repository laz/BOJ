#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<vector <int> > mat;

vector<vector<int> > multiply(vector<vector<int> > a, vector<vector<int> > b){
  
  vector<vector<int> > ret;
  for(int i = 0; i < n; ++i){
    vector<int> tmp;
    for(int j = 0; j < n; ++j){
      int t = 0;
      for(int k = 0; k < n; ++k)
        t += a[i][k] * b[k][j];
      t = t % 1000;
      tmp.push_back(t);
    }
    ret.push_back(tmp);
  }

  return ret;
}

vector<vector<int> > multiplyN(long long b){
  if(b == 1)
    return mat;
  if(b % 2)
    return multiply(multiplyN(b-1), mat);
  
  vector<vector<int> > get = multiplyN(b/2);
  vector<vector<int> > ret = multiply(get, get);

  return ret;
}

int main(){
  int t;
  long long b;
  scanf("%d %lld", &n, &b);
  for(int i =0 ; i < n; ++i){
    vector<int> tmp;
    for(int j = 0 ; j < n; ++j){
      scanf("%d", &t);
      tmp.push_back(t % 1000);
    }
    mat.push_back(tmp);

  }
  vector<vector<int> > res = multiplyN(b);

  for(int i =0 ; i < n; ++i){
    for(int j = 0 ; j < n; ++j)
      printf("%d ", res[i][j]);
    printf("\n");
  }
}