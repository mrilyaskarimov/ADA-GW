//
//  main.cpp
//  9644
//
//  Created by Ilyas Karimov on 9/10/20.
//  Copyright © 2020 Ilyas Karimov. All rights reserved.
//

#include <iostream>

long long powmod(long long x, long long y, long long mod){
    if (x==1 || y==0) return 1;
    if (y%2==0) return powmod(x*x%mod,y/2,mod);
    return x*powmod(x,y-1, mod)%mod;
    
}
int main(int argc, const char * argv[]) {
//    Find the value of the sum (1n + 2n + 2 * 3n + 3 * 4n + 4 * 5n + .... + 99 * 100n) mod m.
    long long n,m, res = 0;
    scanf("%lld %lld", &n,&m);
//    printf("%lld\n", powmod(3,3));
    for(int i = 3; i<=100; i++){
        res += ((i-1)*powmod(i,n, m));
    }
    res += powmod(1,n,m) + powmod(2,n, m);
    printf("%lld", res%m);
}
