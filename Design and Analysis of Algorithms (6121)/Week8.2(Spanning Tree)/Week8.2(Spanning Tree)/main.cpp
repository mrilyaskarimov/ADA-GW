#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAXV 200001
#define MAXE 1000001
#include <iostream>

using namespace std;

struct Edge
{
  int u, v,dist;
} e[MAXE];

int mas[MAXV], _size[MAXV], res;

void swap(int &x, int &y)
{
  int t = x; x = y; y = t;
}

int Repr(int n)
{
  if (n == mas[n]) return n;
  return mas[n] = Repr(mas[n]);
}

int Union(int x,int y)
{
  x = Repr(x); y = Repr(y);
  if(x == y) return 0;

  if (_size[x] < _size[y]) swap(x,y);
  mas[y] = x;
  _size[x] += _size[y];
  return 1;
}

int lt(Edge a, Edge b)
{
  return (a.dist < b.dist);
}

int main(void)
{
//  freopen("in.txt","r",stdin);
  int i, n, m,t,p,q,k,j,sum;
  char ch[MAXV][10];
    
  scanf("%d %d\n", &n, &k);
  
  for(i = 1; i <= n; i++)
  {
    mas[i] = i;
    _size[i] = 1;
  }
  for(i=0;i<n;i++){
      for(j=0;j<k-1;j++){
          scanf("%c",&ch[i][j]);
      }
          scanf("%c",&ch[i][k-1]);
  }
  
//    for(i=0;i<n;i++){
//          for(j=0;j<k;j++){
//            printf("%c",ch[i][j]);
//        }printf("\n");
//    }
  int cnt=0;
  for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
          e[cnt].u=i;
          e[cnt].v=j;
          sum=0;
          for(int w=0;w<k;w++){
              sum+=!(ch[i][w]==ch[j][w]);
          }
          e[cnt].dist=sum;
          cnt++;
      }
  }

  sort(e,e+cnt,lt);

  res = 0;
  string s="";
  char cr[200];
  for(i = 0; i < cnt; i++)
    if (Union(e[i].u,e[i].v)) {
            res += e[i].dist;
            sprintf(cr,"%d %d\n",e[i].u,e[i].v);
            s.append(cr);

    }
  printf("%d\n",res);
     cout<<s;
  return 0;
}
