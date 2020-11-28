//
//  main.cpp
//  Problem L (Dense Forest)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <algorithm>
#include<math.h>
#define EPS 0.0000001
using namespace std;
double a,b, vp, vf, Left, Right, f, g;

double t(double x)
{
    return sqrt(x*x + (1 - a)*(1 - a)) / vp + sqrt(a*a + (1 - x)*(1 - x)) / vf;
}
int main(int argc, const char * argv[]) {
    scanf("%lf %lf %lf",&vp, &vf, &a);
    Left = 0; Right = 1;
    while(Right - Left >= EPS)
    {
        f = Left + (Right - Left) / 3;
        g = Right - (Right - Left) / 3;
        if (t(f) < t(g)) Right = g;
        else Left = f;
    }
    printf("%.9lf\n",Left);
}
