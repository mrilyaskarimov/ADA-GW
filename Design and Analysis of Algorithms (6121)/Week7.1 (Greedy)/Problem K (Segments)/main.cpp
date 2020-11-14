//
//  main.cpp
//  Problem K (Segments)
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

int res, cur, i, num, st,fin;
vector<segment> v;

int f(segment a, segment b)
{
  return a.fin <= b.fin;
}

int main(void)
{

  scanf("%d", &num);
  while (num--)
  {
    scanf("%d %d", &st, &fin);
    v.push_back(segment(st, fin));
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
}
