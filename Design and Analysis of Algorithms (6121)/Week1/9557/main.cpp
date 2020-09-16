//
//  main.cpp
//  9557
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//
//


#include <iostream>

using namespace std;

long long m = 1000000007;

//Return (n*bb(n%m,k-1)%m

long long  binsballs (long long n, long long k){
    if (k == 0) return 1;
    if (k%2 == 0) return (binsballs((n*n)%m, k/2)%m);
    return (n*binsballs(n%m, k-1)%m);
}
int main(int argc, const char * argv[]) {
    long long n;
    scanf("%lld", &n);
    printf("%lld", (n*binsballs(n-1, n-1)));
}
