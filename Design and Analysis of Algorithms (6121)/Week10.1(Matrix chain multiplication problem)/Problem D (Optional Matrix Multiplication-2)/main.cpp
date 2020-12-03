#include <cstdio>
#include <cstring>
#include <string>
#define INF 0x3F3F3F3F3F3F3F3FLL
using namespace std;

#define MAX 11
string Stroka[11] = {"0","1","2","3","4","5","6","7","8","9","10"};

int cs, n, i;
long long m[MAX][MAX], s[MAX][MAX], p[MAX];
string Answer;

long long Mult(int i, int j)
{
  if (m[i][j] == INF)
    for (int k = i; k <= j - 1; k++)
    {
      long long temp = Mult(i,k) + Mult(k+1,j) + p[i-1] * p[k] * p[j];
      if (temp < m[i][j])
      {
        m[i][j] = temp;
        s[i][j] = k;
      }
  }
  return m[i][j];
}

string Print(int i, int j)
{
  if (i == j) return "A" + Stroka[i];
  return "(" + Print(i,s[i][j]) + " x " + Print(s[i][j]+1,j) + ")";
}

int main(void)
{
  //freopen("1521.in","r",stdin);
  cs = 1;
  while(scanf("%d",&n),n)
  {
    memset(m,0x3F,sizeof(m));
    for(i = 1; i <= n; i++)
    {
      scanf("%d %d",&p[i-1],&p[i]);
      m[i][i] = 0;
    }

    Mult(1,n);
    printf("%d\n", Mult(1,n));
    printf("Case %d: ",cs++);
    if (n == 1) Answer = "(A1)"; else Answer = Print(1,n);
    printf("%s\n",Answer.c_str());
  }
  return 0;
}
