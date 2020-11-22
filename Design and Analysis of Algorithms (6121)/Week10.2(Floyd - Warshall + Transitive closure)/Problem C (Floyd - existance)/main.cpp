//
//  main.cpp
//  Problem C (Floyd - existance)
//
//  Created by Ilyas Karimov on 20.11.20.
//

#include <iostream>
#define INF 0x3F3F3F3F
#define MAX 101
int i,j,k, n;
int m[MAX][MAX], res[MAX][MAX];

void floyd(void)
    {
      for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if ((m[i][k] < INF) && (m[k][j] < INF))
        {
            if (m[i][k] + m[k][j] < m[i][j]) m[i][j] = m[i][k] + m[k][j];
            if (m[i][j] < -INF) m[i][j] = -INF;
        }
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
        for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
          scanf("%d",&m[i][j]);
          if ((m[i][j] == 0) && (i != j)) m[i][j] = INF;
        }
    floyd();
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
       if (m[i][j] == INF) res[i][j] = 0;
       else{
           res[i][j]=1;
           for(k = 0; k < n; k++)
                     if ((m[k][k] < 0) && (m[i][k] < INF) && (m[k][j] < INF))
                       res[i][k] = res[i][j] = res[k][j] = 2;
           }
        }
       }
for(i = 0; i < n; i++)
   {
     for(j = 0; j < n; j++)
       printf("%d ",res[i][j]);
     printf("\n");
   }    
}
