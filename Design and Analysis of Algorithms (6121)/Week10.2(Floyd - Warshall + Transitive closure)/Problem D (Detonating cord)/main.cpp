//
//  main.cpp
//  Problem D (Detonating cord)
//
//  Created by Ilyas Karimov on 02.12.20.
//

#include <iostream>
#include<tuple>
#define MAX 101
#define INF 0x3F3F3F3F
using namespace std;
int g[MAX][MAX], a[MAX];
int n, m, k, ai, bi, ti;
tuple < int, int > tup;
void floyd(void)
{
  for (int k = 1; k <= n; k++)
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i<=m; i++){
        scanf("%d %d %d", &ai, &bi, &ti);
        g[ai][bi]=g[bi][ai]=ti;
    }

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= m; j++)
    {
      if ((g[i][j] == 0) && (i != j)) g[i][j] = INF;
    }
    floyd();
    
 
    for (int i = 1; i <= m; i++){
        int max =-1;
        for (int j = 1; j <= m; j++){
            if((g[i][j]> max) && (g[i][j] < INF)) max = g[i][j];
            printf("%d ", g[i][j]);
        }
        a[i]= max;
        puts("\n");
    }
    int min = 800;
    for (int i = 1; i <= m; i++ )
    if(min > a[i]){
        min = a[i];
        tup =  make_tuple(i, min);
    }
    printf("%d %d", get<0>(tup), get<1>(tup));
    
}
