//
//  main.cpp
//  Problem A (Correcting Paranthesization)
//
//  Created by Ilyas Karimov on 24.11.20.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int m[51][51], res;
string s;
//try to write your own version
int enc(char c, char d)
{
  string p = "([{)]}";
  if (p.find(c) / 3 > 0 && p.find(d) / 3 < 1) return 2;
  if (p.find(c) % 3 == p.find(d) % 3 && c != d) return 0;
  return 1;
}

int f(int i, int j)
{
  if (i > j) return 0;
  if (m[i][j] != -1) return m[i][j];

  int r = f(i + 1, j - 1) + enc(s[i], s[j]);

  for (int k = i + 1; k < j; k += 2)
    r = min(r, f(i, k) + f(k + 1, j));
  return m[i][j] = r;
}

int main(void)
{

  while (cin >> s)
  {
    memset(m, -1, sizeof(m));
    res = f(0, s.size() - 1);
    cout << res << endl;
  }
  return 0;
}
