#include <stdio.h>
#include <string.h>
#define SIZE 1002

int arr1[SIZE], arr2[SIZE], mas[2][SIZE];
int n, m, i, j;

int max(int i,int j)
{
  return (i > j) ? i : j;
}

int main(void)
{
  //freopen("1618.in","r",stdin);
  scanf("%d",&n);
  for(i = 1; i <= n; i++) scanf("%d",&arr1[i]);
  scanf("%d",&m);
  for(i = 1; i <= m; i++) scanf("%d",&arr2[i]);

  memset(mas,0,sizeof(mas));
  for(i = 1; i <= n; i++)
  for(j = 1; j <= m; j++)
    if (arr1[i] == arr2[j])
      mas[i%2][j] = 1 + mas[(i+1)%2][j-1];
    else
      mas[i%2][j] = max(mas[(i+1)%2][j],mas[i%2][j-1]);

  printf("%d\n",mas[n%2][m]);
  return 0;
}
