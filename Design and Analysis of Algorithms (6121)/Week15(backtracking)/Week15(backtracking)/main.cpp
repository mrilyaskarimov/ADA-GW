#include <iostream>
#define MAX 101

int g[MAX][MAX], in[MAX];
int n,i,k,x,j;

int main(){
    freopen("/Users/ilyaskarimov/Desktop/444.txt", "r", stdin);

    scanf("%d", &n);

for (i = 1; i <= n; i++)
{
  scanf("%d", &k);
  for (j = 0; j < k; j++)
  {
    scanf("%d", &x);
    g[i][x] = 1;
  }

}


for (i = 1; i <= n; i++){
for (j = 1; j <= n; j++){
  if (g[i][j] == 1) in[j]++;
}
}

int source = 0;

for (i = 1; i <= n; i++)
  if (in[i] == 0) source++;
    printf("%d\n", source);

 
 return 0;

}
