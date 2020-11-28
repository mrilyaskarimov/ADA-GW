
#include <cstdio>
#include <algorithm>
#define MAX 6
using namespace std;

int arr1[MAX], lis[MAX];
int i, n, len, pos;

int main(void)
{
  //freopen("988.in","r",stdin);
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&arr1[i]);

  for (len = i = 0; i < n; i++)
  {
    pos = lower_bound(lis,lis+len,arr1[i]) - lis;
    if (pos < len) lis[pos] = arr1[i];
    else lis[len++] = arr1[i];
  }

    printf("%d\n",len);
    for(i = 0; i < len; i++) printf("%d ", lis[i]);
  return 0;
}
