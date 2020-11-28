//
//  main.cpp
//  Problem K (Ternary search)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#define EPS 0.0000001
using namespace std;
double a,b;

double f(double x)
{
    return x * x + a * x + b;
}
double triple(double f(double x), double a, double b)
{
    double g, h;
    while (b - a > EPS)
    {
        g = a + (b - a) / 3;
        h = a + 2 * (b - a) / 3;
        if (f(g) <= f(h)) b = h;
        else a = g;
    }
    return (a + b) / 2;
}
int main(int argc, const char * argv[]) {
    
    scanf("%lf %lf", &a, &b);
    double x = triple(f, -100, 100);
    printf("%.2lf\n", x);
}
