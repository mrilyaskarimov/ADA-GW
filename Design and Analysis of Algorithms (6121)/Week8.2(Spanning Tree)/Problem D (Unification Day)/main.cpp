//
//  main.cpp
//  Problem D (Unification Day)
//
//  Created by Ilyas Karimov on 22.11.20.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 5001

int x[MAX], y[MAX];
int i, j, v, to, n;
int used[MAX], min_e[MAX], end_e[MAX];
double dist;

int dist2(int i, int j)
{
  return (x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]);
}

int main(void)
{
  //freopen("2967.in","r",stdin);
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d %d",&x[i], &y[i]);

  memset(min_e,0x3F,sizeof(min_e));
  memset(end_e,-1,sizeof(end_e));
  memset(used,0,sizeof(used));

  dist = min_e[1] = 0;
  for (i = 0; i < n; i++){
    v = -1;
    for (j = 0; j < n; j++)
      if (!used[j] && (v == -1 || min_e[j] < min_e[v])) v = j;

    used[v] = 1;
    if (end_e[v] != -1) dist += sqrt((double)dist2(v,end_e[v]));

    for (to = 0; to < n; to++)
    {
      int dV_TO = dist2(v,to);
      if (!used[to] && (dV_TO < min_e[to]))
      {
        min_e[to] = dV_TO;
        end_e[to] = v;
      }
    }
  }

  printf("%.6lf\n",dist);
  return 0;
}
