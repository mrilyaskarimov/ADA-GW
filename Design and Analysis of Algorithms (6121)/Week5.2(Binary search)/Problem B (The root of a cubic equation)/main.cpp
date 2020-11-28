//
//  main.cpp
//  Problem B (The root of a cubic equation)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#include <math.h>
#define EPS 1e-12

using namespace std;
int a,b,c,d;
double f(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

int main(int argc, const char * argv[]) {
   
    scanf("%d %d %d %d", &a, &b,&c, &d);
    double r = 1;
    while(f(r)*f(-r)>=0) r *=2;
    double l = -r;
    while(r-l > EPS){
        double mid = (l+r)/2;
        if(f(mid)*f(r)>0) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
}
