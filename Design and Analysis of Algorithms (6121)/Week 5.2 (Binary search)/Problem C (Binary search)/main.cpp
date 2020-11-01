//
//  main.cpp
//  Problem C (Binary search)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <stdio.h>
#define MAX 1000000

int i, n, q, x;
int m[MAX];

int my_bin_search(int *m, int start, int end, int x)
{
  while (start < end)
  {
    int mid = (start + end) / 2;
    if (x > m[mid])
      start = mid + 1;
    else
      end = mid;
  }
  return m[start] == x;
}

int main(void)
{
  //freopen("9016.in", "r", stdin);
  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++)
    scanf("%d", &m[i]);

  for (i = 0; i < q; i++)
  {
    scanf("%d", &x);
    if(my_bin_search(m,0,n-1,x))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
