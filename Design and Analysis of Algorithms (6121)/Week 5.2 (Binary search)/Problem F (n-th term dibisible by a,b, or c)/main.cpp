//
//  main.cpp
//  Problem F (n-th term dibisible by a,b, or c)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#define MAX 1000000000

using namespace std;


long long gcd (long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a >=b) return gcd (a%b, b);
    return gcd (a, b%a);
}
long long lcm (long long a, long long b) {
    return a*b/gcd(a,b);
}

long long f(long long a, long long b,long long c, long long n){
    return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(a, lcm(b,c));
}

int main(int argc, const char * argv[]) {
    long long a, b,c, n;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
    long long start = 1, end = MAX;
    while (start < end){
      long long mid = (start + end) / 2;
      if (f(a, b, c, mid) < n) start = mid +1;
      else end = mid;
    }
    printf("%lld", start);
}
