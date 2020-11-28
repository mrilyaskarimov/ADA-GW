//
//  main.cpp
//  Problem A (Square root)
//
//  Created by Ilyas Karimov on 10/9/20.
//

#include <iostream>
#include <cmath>

#define EPS 1e-10


double x, c, left, right, middle, y;
double f(double x)
{
return x * x + sqrt(x);
}

int main(int argc, const char * argv[]) {
     
    scanf("%lf",&c);
    left = 0; right = c;
      while(right - left > EPS)
      {
        middle = (left + right)/ 2;
        y = f(middle);
        if (y > c) right = middle; else left = middle;
      }
      printf("%lf\n",left);
      return 0;
}
