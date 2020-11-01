//
//  main.cpp
//  Problem E (n-th integer dibisible by a or b)
//
//  Created by Ilyas Karimov on 31.10.20.
//

#include <iostream>
#define MAX 1000000000

using namespace std;
int m[MAX];

int gcd (int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a >=b) return gcd (a%b, b);
    return gcd (a, b%a);
}
int lcm (int a, int b) {
    return a*b/gcd(a,b);
}
int f(int a, int b, int n){
    return n/a + n/b - n/lcm(a,b);
}

int main(int argc, const char * argv[]) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    int start = 1, end = MAX;
    while (start < end)
    {
      int mid = (start + end) / 2;
      if (f(a,b,mid) < n)
          start = mid +1;
      else
          end = mid;
    }
    printf("%d", start);
}
