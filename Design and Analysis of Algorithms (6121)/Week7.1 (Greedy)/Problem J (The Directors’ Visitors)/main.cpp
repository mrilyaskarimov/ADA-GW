//
//  main.cpp
//  Problem J (The Directors’ Visitors)
//
//  Created by Ilyas Karimov on 11.11.20.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class segment
{
public:
  int start, fin;
  segment(int start, int fin) : start(start), fin(fin) {}
};

int res, cur, i, n, h1, m1, h2, m2;
vector<segment> v;

int f(segment a, segment b)
{
  return a.fin <= b.fin;
}

int main(void)
{
  //freopen("66.in", "r", stdin);
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    v.push_back(segment(h1 * 60 + m1, h2 * 60 + m2));
  }

  sort(v.begin(), v.end(), f);

  cur = 0; res = 1;
  for (i = 1; i < v.size(); i++)
  {
    if (v[i].start >= v[cur].fin)
    {
      cur = i;
      res++;
    }
  }

  printf("%d\n", res);
  return 0;
}
