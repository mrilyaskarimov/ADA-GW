//
//  main.cpp
//  Problem G (K-th minimum)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <iostream>
#include <vector>
using namespace std;
//
//P(x) = 132x3 + 77x2 + 1345x + 1577

vector<long long> v;
long long n, k, i;

long long P(long long x){
    return (132*x*x*x + 77*x*x + 1345*x + 1577)%1743;
}
long long Partition(long long left, long long right)
{
  long long x = v[left], i = left - 1, j = right + 1;
  while (1)
  {
    do j--; while (v[j] > x);
    do i++; while (v[i] < x);
    if (i < j) swap(v[i], v[j]); else return j;
  }
}

long long kth(long long k, long long left, long long right)
{
  if (left == right) return v[left];
  long long pos = Partition(left, right);
  if (k <= pos) return kth(k, left, pos);
  else return kth(k, pos + 1, right);
}
int main(int argc, const char * argv[]) {
    scanf("%lld %lld", &n, &k);
    v.resize(n + 1);
    for (i = 1; i <= n; i++){
        v[i]=P(i);
    }
    kth(k, 1, n);
    printf("%lld\n", v[k]);
    return 0;
}
