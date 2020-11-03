//
//  main.cpp
//  Problem H (Find an element)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
long long n, k, i;

long long Partition(long long left, long long right)
{
  long x = v[left], i = left - 1, j = right + 1;
  while (1)
  {
    do j--; while (v[j] < x);
    do i++; while (v[i] > x);
    if (i < j) swap(v[i], v[j]); else return j;
  }
}

long long kth(long long k, long long left, long long right)
{
  if (left == right) return v[left];
  long long pos = Partition(left, right);
  if (k <= pos) return kth(k, left, pos);
  else return kth(k, pos + 1 , right);
}

int main(void)
{
    scanf("%lld %lld", &n, &k);
    v.resize(n + 1);
    for (i = 1; i <= n; i++) scanf("%lld", &v[i]);
    
    printf("%lld\n", kth(k, 1, n));
//    Partition(v[1],v[n]);
//    for(i =1; i<=n; i++) printf("%d ", v[i]);
    return 0;
}
