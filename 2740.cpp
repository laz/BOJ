#include <cstdio>
using namespace std;

int mat[3][100][100];
int size[2][2];

int main(){
  for(int i = 0; i < 2; ++i){
    scanf("%d %d", &size[i][0], &size[i][1]);
    for(int j = 0; j < size[i][0]; ++j)
      for(int k = 0; k < size[i][1]; ++k)
        scanf("%d", &mat[i][j][k]);
  }
  
  for(int i = 0; i < size[0][0]; ++i)
    for(int j = 0 ; j < size[1][1]; ++j)
      for(int k = 0; k < size[1][0]; ++k)
        mat[2][i][j] += mat[0][i][k] * mat[1][k][j];

  for(int i = 0 ; i < size[0][0]; ++i)
    for(int j = 0 ; j < size[1][1]; ++j)
      printf("%d%c", mat[2][i][j], (j==size[1][1]-1) ? '\n' : ' ');
}
